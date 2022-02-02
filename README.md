# minishell
As beautiful as a shell

## Final grade : /125

Mandatory part : /100

Bonus : 0/25


### How to use it

Using ``make`` will create the ``minishell`` executable.

Run it with:

```
./minishell
```
* Running with arguments will throw you an error, like bash. 
* In addition #1, if any question about the usage occurs, take bash as a reference. 
* In addition #2, if you find any mistake, feel free to inform me or [mseastar](https://github.com/mseastar), thx.


### Available options

Minishell runs executables from an absolute, relative or environment PATH (``/bin/ls`` or ``ls``), including arguments or options. ``'`` and ``"`` work the same as bash, except for multiline commands.

You can use redirections ``>`` ``>>`` ``<`` ``<<`` as well as pipes ``|`` and mixing up them together, however you like.

Environment variables are handled, like ``$HOME``, including the return code ``$?``, .

Finally, you can use ``Ctrl-C`` to interrupt and ``Ctrl-\`` to quit a program, as well as ``Ctrl-D`` to throw an EOF, same as in bash.

A few of the functions are "built-in", meaning we don't call the executable, we re-coded them directly. It's the case for ``echo``, ``pwd``, ``cd``, ``env``, ``export``, ``unset`` and ``exit``.


### Credit

This two-person project was done with [mseastar](https://github.com/mseastar).


### Workflow
*(In russian, sry)*

<p align="center">
  <img src="https://github.com/tsegeron/Images/blob/master/workflow.png" width="100%" />
</p>
