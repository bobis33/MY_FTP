# EPITECH Project | B-NWP-400 | my_ftp

<img src="doc/Epitech_banner.png" alt="Architecture">

## Description

The goal of this project is to create a FTP server [RFC959 compliant](https://www.rfc-editor.org/rfc/rfc959).
The network communication will be achieved through the use of TCP sockets.

## Usage


```bash
$> make
[...]
./myftp [port] [path]
        port  is the port number on which the server socket listens
        path  is the path to the home directory for the Anonymous user
```

### Launch tests

```bash
$> make tests_run
[...]
```

### Debug mode

```bash
$> make debug
[...]
$> valgrind --leak-check=full --show-leak-kinds=all -s ./myftp [port] [path]
```

## Commit Norms

| Commit Type | Description                                                                                                               |
|:------------|:--------------------------------------------------------------------------------------------------------------------------|
| build       | Changes that affect the build system or external dependencies (npm, make, etc.)                                           |
| ci          | Changes related to integration files and scripts or configuration (Travis, Ansible, BrowserStack, etc.)                   |
| feat        | Addition of a new feature                                                                                                 |
| fix         | Bug fix                                                                                                                   |
| perf        | Performance improvements                                                                                                  |
| refactor    | Modification that neither adds a new feature nor improves performance                                                     |
| style       | Change that does not affect functionality or semantics (indentation, formatting, adding space, renaming a variable, etc.) |
| docs        | Writing or updating documentation                                                                                         |
| test        | Addition or modification of tests                                                                                         |
