Roadmap técnico detalhado do Minishell

1. **Leitura da linha**

* Use a função `readline()` para capturar a entrada do usuário.
* Armazene o histórico com `add_history()` se a linha não estiver vazia.
* Trate `CTRL+D` retornando `exit` e liberando memória.
* Garanta que a string capturada termine com `\0`.

2. **Parsing**

* Implemente uma função `lexer()` que percorre cada caractere.
* Separe tokens por espaço e operadores (`|`, `>`, `<`).
* Se encontrar aspas simples `'` ou duplas `"`, chame uma função auxiliar `parse_quotes()` para ler até a aspa correspondente.
* Crie uma lista ligada de tokens com tipo definido:

  * `WORD`
  * `PIPE`
  * `REDIRECT_IN`
  * `REDIRECT_OUT`
  * `APPEND`
  * `HEREDOC`
* Armazene também flags internas como `quoted` e `expandable`.
* Exemplo: `"Santos Lima"` gera um token `WORD` com `quoted = 1`.

3. **Verificação sintática**

* Crie uma função `check_syntax()` que percorre os tokens.
* Verifique:

  * Primeiro token não pode ser operador.
  * Nenhum operador pode ser seguido por outro operador.
  * Heredoc e redirecionamentos devem ser seguidos por um `WORD`.
* Retorne erro com mensagem `"syntax error"` e código `258`.

4. **Expansão**

* Implemente `expand_variables()` que percorre tokens `WORD`.
* Use a função `getenv()` ou uma lista local para substituir variáveis.
* Exemplo: `$HOME` vira `/home/usuario`.
* Trate `$?` para retornar o valor da última execução.
* Ignore expansão em tokens com `quoted = 1` e aspas simples.
* Expanda com cuidado em aspas duplas, preservando espaços internos.

5. **Construção da estrutura de comando**

* Crie uma struct `t_cmd`:

  ```c
  typedef struct s_cmd {
      char **argv;
      int infile;
      int outfile;
      struct s_cmd *next;
  } t_cmd;
  ```
* Percorra os tokens e monte a lista encadeada de comandos.
* Para cada `PIPE`, inicie um novo nó.
* Preencha `argv` com os `WORD` consecutivos.
* Configure `infile` e `outfile` conforme os redirecionamentos.
* Exemplo: `echo hello | grep h > out.txt` gera dois `t_cmd`.

6. **Redirecionamentos**

* `>` abre o arquivo com `O_CREAT | O_WRONLY | O_TRUNC`.
* `>>` abre com `O_CREAT | O_WRONLY | O_APPEND`.
* `<` abre com `O_RDONLY`.
* `<<` cria um here_doc:

  * Use `pipe()` para criar um descritor temporário.
  * Leia até encontrar o delimitador.
  * Escreva o conteúdo no descritor de entrada.

7. **Execução**

* Implemente `executor()` que percorre a lista `t_cmd`.
* Para cada comando:

  * Se houver `PIPE`, use `pipe()` para criar conexão entre processos.
  * Use `fork()` para criar processos filhos.
  * No filho:

    * Redirecione `stdin` e `stdout` conforme `infile` e `outfile`.
    * Feche descritores não usados.
    * Se o comando for builtin, execute diretamente.
    * Caso contrário, use `execve()` com o caminho correto.
  * No pai:

    * Feche descritores intermediários.
    * Aguarde filhos com `waitpid()`.

8. **Builtins**
   Implemente manualmente as funções internas:

* `echo`: imprime com tratamento de `-n`.
* `cd`: usa `chdir()` e atualiza `PWD` e `OLDPWD`.
* `pwd`: usa `getcwd()`.
* `export`: adiciona ou substitui variáveis no ambiente.
* `unset`: remove variáveis.
* `env`: imprime o ambiente atual.
* `exit`: encerra o shell com o código fornecido.

9. **Variáveis de ambiente**

* Copie o `envp` inicial para uma lista ligada `t_env`:

  ```c
  typedef struct s_env {
      char *name;
      char *value;
      struct s_env *next;
  } t_env;
  ```
* Use funções auxiliares:

  * `get_env(name)` para buscar.
  * `set_env(name, value)` para atualizar.
  * `unset_env(name)` para remover.
* Atualize dinamicamente após `export` e `unset`.

10. **Sinais**

* No processo principal:

  * `SIGINT`: imprime uma nova linha e reexibe o prompt.
  * `SIGQUIT`: ignora.
* Nos filhos:

  * Restaure o comportamento padrão (`SIG_DFL`).
* Use `sigaction()` em vez de `signal()`.

11. **Gestão de memória**

* Após cada comando, libere todos os tokens, listas e argv.
* Implemente funções como `free_tokens()`, `free_env()`, `free_cmds()`.
* Teste com `valgrind` e garanta zero leaks.

12. **Estrutura de pastas**

```
src/
  main.c
  lexer.c
  parser.c
  syntax.c
  expand.c
  exec.c
  redirect.c
  builtins/
      echo.c
      cd.c
      ...
  signals.c
  utils.c
includes/
  minishell.h
```

13. **Macros e constantes**

* Defina códigos de erro em `minishell.h`:

  ```c
  #define SUCCESS 0
  #define SYNTAX_ERROR 258
  #define GENERAL_ERROR 1
  ```
* Defina flags para tipos de token.

14. **Loop principal**

```c
while (1) {
    line = readline("minishell$ ");
    if (!line)
        exit_shell();
    add_history(line);
    tokens = lexer(line);
    if (check_syntax(tokens))
        continue;
    expand_variables(tokens, env);
    cmds = parse_commands(tokens);
    executor(cmds, env);
    free_all(tokens, cmds);
}
```

15. **Testes práticos**

* echo “hello world”
* echo $USER
* ls | grep a > out.txt
* export VAR=42; echo $VAR
* echo “unterminated
* cd /; pwd
* exit 42

Este roadmap fornece a ordem exata de implementação, estrutura de dados, chamadas de sistema e comportamento esperado para cada parte do minishell.

