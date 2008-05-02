/*
** minishell.h for minishell1 in /u/epitech_2012/lefebv_l/cu/rendu/c/minishell1
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Thu Feb 21 18:03:20 2008 laurent lefebvre
** Last update Fri May  2 15:41:10 2008 nicolas mondange
*/

#ifndef _MINISHELL_H_
#define _MINISHELL_H_

/* includes */
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>

/* defines */
#define	MAX_SIZE	2048

#define	ENV	params->env
#define	NAME	params->name
#define	HOST	params->host
#define	PWD	params->pwd
#define	HOME	params->home
#define	BIN	params->bin
#define	BIN_NBR	params->bin_nbr
#define	PATH	params->path
#define	MODE	params->mode

/* struct */

/* Struct list chaine pour l'historique */

typedef struct		s_event
{
  char			*nbr;
  char			*time;
  char			*info;
  struct s_event	*next;
}			t_event;

/* Struct SH */

typedef struct	s_sh
{
  int		name;
  int		host;
  int		pwd;
  int		bin;
  int		bin_nbr;
  char		home[512];
  char		path[1024];
  int		mode;
  char		**env;
}		t_sh;

/* files */
/* main.c */

/* shell.c */
void	clear_buffer(char buffer[MAX_SIZE]);
void	shell();

/* gere_redirect.c */
void	gere_redirect(t_sh *params, char *buffer, int mode);

/* gere_pipe.c */
void	gere_pipe(t_sh *params, char *buffer);

/* gere_dotcoma.c */
void	get_cmd1(t_sh *params, char *buffer, char *new);
void	get_cmd2(t_sh *params, char *buffer, char *new);
void	gere_dotcoma(t_sh *params, char *buffer);

/* builtins.c */
int	my_strcmp(char *s1, char *s2);
int	is_builtins(t_sh *params, char *buffer);

/* builtins_lib.c */
int	my_cd(t_sh *params, char *buff);
int	my_exit(t_sh *params);
int	my_repeat(t_sh *params, char *buff, int i, int n, int k);

/* my_cd.c */
int	cd_prev(char *pwd);
void	blank_buffer(char *buffer);
int	change_dir(t_sh *params, char *buff, int i);
int	my_cd(t_sh *params, char *buff);

/* my_setenv.c */
int	my_setenv(t_sh *params, char *buffer, int i);
int	my_unsetenv(t_sh *params, char *buffer);

/* get_bin.c */
void	get_info_0(t_sh *params);
void	get_info_1(t_sh *params);
void	get_info_2(t_sh *params);
void	dir_nbr(t_sh *params);
void	get_bin(t_sh *params);

/* command.c */
void	get_newpath(int i, t_sh *params, char *buffer);
void	clear_path(t_sh *params);
void	command(t_sh *params, char *buffer, int mode);

/* exec.c */
void	execute(t_sh *params, char *buffer);
void	exec_command(t_sh *params, char *buffer, int mode);

/* my_exec.c */
int	my_exec(t_sh *params, char *buffer);

/* display.c */
void	prompt(t_sh *params);

/* gere_canonical.c */
int	my_cout(int c);
char	*xtgetstr(char *cap, char **area);
void	put_cap(char *cap, int mode);
void	canonical(int i);

/* lib_01.c */
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);

/* lib_02.c */
int	is_match(char *str, char c);
void	freetab(char **tab);
int	arg_pipe_nbr(char *str, int i, int n);

/* lib_03.c */
int	arg_nbr(char *str, char c1, char c2);
int	arg_len(char *str, char c1, char c2, int mode);
int	*proto_arg(char *str, char c1, char c2);
char	**my_gettab(char *str, char c1, char c2);

/* error_01.c */
void	*xmalloc(int size);
int	xopen(char *path, int flags);
int	xread(int fd, void *buf, int nbytes);
int	xclose(int fd);
void	bad_command(char *cmd);

/* error_02.c */
void	quotefail(char quote);
void	xchdir(char *path);
void	envfail(char *error, t_sh *params);
int	verbose(char *error);
int	xpipe(int p[2]);

/* error_03.c */
pid_t	xfork();

#endif /* _MINISHELL_H_*/
