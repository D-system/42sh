/*
** xwait.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Fri Apr 25 16:04:12 2008 thomas brennetot
** Last update Tue May 27 19:34:15 2008 aymeric derazey
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "42.h"

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
    {SIGABRT, "Abort()"},
    {SIGFPE, "Floating exception"},
    {SIGKILL, "Kill (cannot be caught or ignored)"},
    {SIGBUS, "Bus error"},
    {SIGSEGV, "Segmentation Fault"},
    {SIGSTOP, "Sendable stop signal not from tty"},
    {SIGTSTP, "Suspend"},
    {SIGXFSZ, "Exceeded file size limit"},
    {SIGPIPE, "Write on a pipe with no one to read it"},
#if Linux
    {SIGTHR, "Thread interrupt."},
#endif
    /*     {SIGTRAP, "Trace trap (not reset when caught)"}, */
/*     {SIGEMT, "EMT instruction"}, */
/*     {SIGSYS, "Non-existent system call invoked"}, */
/*     {SIGALRM, "Alarm clock"}, */
/*     {SIGTERM, "Software termination signal from kill"}, */
/*     {SIGURG, "Urgent condition on IO channel"}, */
/*     {SIGCONT, "Continue a stopped process"}, */
/*     {SIGCHLD, "To parent on child stop or exit"}, */
/*     {SIGTTIN, "To readers pgrp upon background tty read"}, */
/*     {SIGTTOU, "Like TTIN if (tp->t_local&LTOSTOP)"}, */
/*     {SIGIO, "Input/output possible signal"}, */
/*     {SIGXCPU, "Exceeded CPU time limit"}, */
/*     {SIGVTALRM, "Virtual time alarm"}, */
/*     {SIGPROF, "Profiling time alarm"}, */
/*     {SIGINFO, "Information request"}, */
    {0, 0},    
  };

void		err_status(int *status)
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
	      return ;
	    }
	  i++;
	}
    }
}

int		xwaitpid(int wait_pid, int *status, int options)
{
  if (waitpid(wait_pid, status, options) == -1)
    return (EXIT_FAILURE);
  if (*status != 0)
    {
      err_status(status);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
