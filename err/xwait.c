/*
** xwait.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Fri Apr 25 16:04:12 2008 thomas brennetot
** Last update Mon Apr 28 12:31:41 2008 thomas brennetot
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "../42.h"

typedef struct	s_wait
{
  int		nb_signal;
  char		*str;
}		t_wait;

t_wait		st_wait[] =
  {
    {SIGHUP, "Hangup\n"},
    {SIGINT, "Interrupt\n"},
    {SIGQUIT, "Quit\n"},
    {SIGILL, "Illegal instr. (not reset when caught)\n"},
    {SIGTRAP, "Trace trap (not reset when caught)\n"},
    {SIGABRT, "Abort()\n"},
    {SIGEMT, "EMT instruction\n"},
    {SIGFPE, "Floating point exception\n"},
    {SIGKILL, "Kill (cannot be caught or ignored)\n"},
    {SIGBUS, "Bus error\n"},
    {SIGSEGV, "Segmentation Fault\n"},
    {SIGSYS, "Non-existent system call invoked\n"},
    {SIGPIPE, "Write on a pipe with no one to read it\n"},
    {SIGALRM, "Alarm clock\n"},
    {SIGTERM, "Software termination signal from kill\n"},
    {SIGURG, "Urgent condition on IO channel\n"},
    {SIGSTOP, "Sendable stop signal not from tty\n"},
    {SIGTSTP, "Stop signal from tty\n"},
    {SIGCONT, "Continue a stopped process\n"},
    {SIGCHLD, "To parent on child stop or exit\n"},
    {SIGTTIN, "To readers pgrp upon background tty read\n"},
    {SIGTTOU, "Like TTIN if (tp->t_local&LTOSTOP)\n"},
    {SIGIO, "Input/output possible signal\n"},
    {SIGXCPU, "Exceeded CPU time limit\n"},
    {SIGXFSZ, "Exceeded file size limit\n"},
    {SIGVTALRM, "Virtual time alarm\n"},
    {SIGPROF, "Profiling time alarm\n"},
    {SIGWINCH, "Window size changes\n"},
    {SIGINFO, "Information request\n"},
    {SIGUSR1, "User defined signal 1\n"},
    {SIGUSR2, "User defined signal 2\n"},
    {SIGTHR, "Thread interrupt.\n"},
    {0, 0},    
  };

int		xwait(int *status)
{
  int		pid;
  int		i;

  pid = wait(status);
  if (*status != 0)
    {
      i = 0;
      while (st_wait[i].nb_signal != 0)
	{
	  if (st_wait[i].nb_signal == *status)
	    {
	      my_printf("%E", st_wait[i].str);
	      return (EXIT_FAILURE);
	    }
	  i++;
	}
    }
  return (EXIT_SUCCESS);
}
