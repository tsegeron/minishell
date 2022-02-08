# Minishell
*As beautiful as a shell*



### Final grade : 100/125

Mandatory part : 100/100

Bonus : 0/25

*******

### Cases

You can find different cases [Here](https://github.com/tsegeron/minishell/tree/main/examples).

*******

### How to use it

Use ``make`` to create the ``minishell`` executable.

Run it with:

```
./minishell
```
* Running with arguments will throw you an error, like bash. 
* In addition #1, if any question about the usage occurs, take bash as a reference. 
* In addition #2, if you find any mistake, feel free to inform me or [mseastar](https://github.com/mseastar), thx.

*******

### Available options

Minishell runs executables from an absolute, relative or environment PATH (``ls`` or ``/bin/ls`` or ``~/../../bin/ls``), including arguments or options. ``'`` and ``"`` work the same as bash, except for multiline commands.

Our minishell also can run itself or other executables, ``SHLVL`` would be change accordingly.

You can use redirections ``>`` ``>>`` ``<`` ``<<`` as well as pipes ``|`` and mixing them up together, however you'd like.

Environment variables are handled, like ``$HOME`` ``$PWD`` ``$PATH`` etc., including the return code ``$?``.

Additionally, you can try launching minishell with PATH being unset, or launch minishell then unset PATH, built-ins should work, but not other cmds.

Finally, you can use signals ``Ctrl-C``, ``Ctrl-\``, ``Ctrl-D`` in non-interactive, interactive and with blocking cmds as ``cat``, ``grep``.

A few of the functions are "built-in", meaning we don't call the executable, we re-coded them directly. It's the case for ``echo``, ``pwd``, ``cd``, ``env``, ``export``, ``unset`` and ``exit``.

*******

### Credits

This two-person project was done with [mseastar](https://github.com/mseastar).

*******

### Workflow
*(In russian, sry)*

<p align="center">
  <img src="https://github.com/tsegeron/minishell/blob/main/examples/workflow.png" width="100%" />
</p>
