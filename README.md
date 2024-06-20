<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <header>
        <h1>42_cursus_get_next_line</h1>
        <p>A function to read a line from a file descriptor, line by line.</p>
    </header>

    <nav>
        <h2>Table of Contents</h2>
        <ul>
            <li><a href="#introduction">Introduction</a></li>
            <li><a href="#common-instructions">Common Instructions</a></li>
            <li><a href="#mandatory-part">Mandatory Part</a></li>
            <li><a href="#details">Details</a></li>
            <li><a href="#bonus-part">Bonus Part</a></li>
            <li><a href="#compilation">Compilation</a></li>
        </ul>
    </nav>

    <section id="introduction">
        <h2>Introduction</h2>
        <p>This project aims to develop a function that returns a line read from a file descriptor. It will help you learn about static variables in C and add a useful function to your collection.</p>
    </section>

    <section id="common-instructions">
        <h2>Common Instructions</h2>
        <ul>
            <li>The project must be written in C and conform to the coding norm.</li>
            <li>Functions should not stop unexpectedly (segmentation fault, bus error, etc.) except for undefined behaviors.</li>
            <li>All heap allocated memory must be properly freed when necessary. No leaks will be tolerated.</li>
            <li>A Makefile must be provided, compiling the source files with appropriate flags and not relinking.</li>
            <li>The Makefile must contain at least the rules: <code>$(NAME)</code>, <code>all</code>, <code>clean</code>, <code>fclean</code>, and <code>re</code>.</li>
        </ul>
    </section>

    <section id="mandatory-part">
        <h2>Mandatory Part</h2>
        <p>Implement the function <code>get_next_line()</code> that reads a line from a file descriptor.</p>
        <ul>
            <li><strong>Function name:</strong> <code>get_next_line</code></li>
            <li><strong>Prototype:</strong> <code>char *get_next_line(int fd);</code></li>
            <li><strong>Files to turn in:</strong> <code>get_next_line.h</code>, <code>get_next_line.c</code>, <code>get_next_line_utils.c</code></li>
            <li><strong>Parameters:</strong> <code>fd</code> - The file descriptor to read from</li>
            <li><strong>Return value:</strong> The line read, or <code>NULL</code> if nothing else to read or an error occurred</li>
            <li><strong>External functions allowed:</strong> <code>read</code>, <code>malloc</code>, <code>free</code></li>
        </ul>
    </section>

    <section id="details">
        <h3>Details</h3>
        <ul>
            <li>Successive calls to <code>get_next_line()</code> should read the entire text file, one line at a time.</li>
            <li>The function should return the line read followed by a newline, unless the end of the file is reached and it does not end with a newline.</li>
            <li>The <code>get_next_line.h</code> header file must contain at least the prototype of the function.</li>
            <li>The <code>get_next_line_utils.c</code> file should contain any additional helper functions required for <code>get_next_line()</code>.</li>
            <li>Your program must compile with the option <code>-D BUFFER_SIZE=n</code> to specify the buffer size for read() calls.</li>
        </ul>
    </section>

    <section id="bonus-part">
        <h2>Bonus Part</h2>
        <p>For those who complete the mandatory part perfectly, you can implement the following bonuses:</p>
        <ul>
            <li>Implement <code>get_next_line()</code> using a single static variable.</li>
            <li>Allow <code>get_next_line()</code> to handle multiple file descriptors simultaneously without losing track of each file descriptor's content.</li>
        </ul>
        <p>Bonus files should have the suffix <code>_bonus.[c|h]</code> and include:</p>
        <ul>
            <li><code>get_next_line_bonus.c</code></li>
            <li><code>get_next_line_bonus.h</code></li>
            <li><code>get_next_line_utils_bonus.c</code></li>
        </ul>
    </section>

    <section id="compilation">
        <h2>Compilation</h2>
        <p>Compile the library using the Makefile provided, ensuring all rules like <code>all</code>, <code>clean</code>, <code>fclean</code>, and <code>re</code> are present to manage the library properly.</p>
    </section>
</body>
</html>
