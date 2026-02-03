/*
exec() replaces the current process image with a new program while keeping the same process ID.

Function	Description
execl()	    Arguments as list
execv()	    Arguments as array
execlp()	Search program in PATH
execvp()	PATH + argv array
execle()	With environment
execve()	Actual system call

Function	PATH Search  	Args Type	 Environment
execl	       no	        List	     Inherited
execv	       no	        Array	     Inherited
execlp	       yes	        List	     Inherited
execvp	       yes	        Array	     Inherited
execle	       no	        List	     Custom
execve	       no	        Array	     Custom

l → list
v → vector (array)
p → PATH
e → environment
*/

