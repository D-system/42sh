/*
** xwait.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Fri Apr 25 16:04:12 2008 thomas brennetot
** Last update Wed Apr 30 11:55:53 2008 thomas brennetot
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include "../42.h"

typedef struct	s_wait
{
  int		nb_signal;
  char		*str;
}		t_wait;

t_wait		gl_wait[] =
  {
    {SIGHUP, "Hangup"},
    {SIGINT, "Interrupt"},
    {SIGQUIT, "Quit"},
    {SIGILL, "Illegal instr. (not reset when caught)"},
    {SIGTRAP, "Trace trap (not reset when caught)"},
    {SIGABRT, "Abort()"},
    {SIGEMT, "EMT instruction"},
    {SIGFPE, "Floating point exception"},
    {SIGKILL, "Kill (cannot be caught or ignored)"},
    {SIGBUS, "Bus error"},
    {SIGSEGV, "Segmentation Fault"},
    {SIGSYS, "Non-existent system call invoked"},
    {SIGPIPE, "Write on a pipe with no one to read it"},
    {SIGALRM, "Alarm clock"},
    {SIGTERM, "Software termination signal from kill"},
    {SIGURG, "Urgent condition on IO channel"},
    {SIGSTOP, "Sendable stop signal not from tty"},
    {SIGTSTP, "Stop signal from tty"},
    {SIGCONT, "Continue a stopped process"},
    {SIGCHLD, "To parent on child stop or exit"},
    {SIGTTIN, "To readers pgrp upon background tty read"},
    {SIGTTOU, "Like TTIN if (tp->t_local&LTOSTOP)"},
    {SIGIO, "Input/output possible signal"},
    {SIGXCPU, "Exceeded CPU time limit"},
    {SIGXFSZ, "Exceeded file size limit"},
    {SIGVTALRM, "Virtual time alarm"},
    {SIGPROF, "Profiling time alarm"},
    {SIGWINCH, "Window size changes"},
    {SIGINFO, "Information request"},
    {SIGUSR1, "User defined signal 1"},
    {SIGUSR2, "User defined signal 2"},
    {SIGTHR, "Thread interrupt."},
    {0, 0},    
  };

int		err_status(int *status)
{
  int		i;

  if (*status != 0)
    {
      i = 0;
      while (gl_wait[i].nb_signal != 0)
	{
	  if (gl_wait[i].nb_signal == *status)
	    {
	      my_printf("%E%E", gl_wait[i].str, "\n");
	      return (EXIT_FAILURE);
	    }
	  i++;
	}
    }
  return (EXIT_FAILURE);
}

int		xwait(int *status)
{
  if (wait(status) == -1)
    {
      my_printf("%E", "Problem with wait\n");
      return (EXIT_FAILURE);
    }
  if (*status != 0)
    return (err_status(status));
  usleep(100);
  return (EXIT_SUCCESS);
}

int		xwait4(int wait_pid, int *status, int options, struct rusage *rusage)
{
  if (wait4(wait_pid, status, options, rusage) == -1)
    {
      my_printf("%E", "Problem with wait4\n");
      return (EXIT_FAILURE);
    }
  if (*status != 0)
    return (err_status(status));
  usleep(100);
  return (EXIT_SUCCESS);
}
