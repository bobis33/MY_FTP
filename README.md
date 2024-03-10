# EPITECH Project | B-NWP-400 | my_ftp

<img src="doc/Epitech_banner.png" alt="Architecture">

## Description

The goal of this project is to create a FTP server [RFC959 compliant](https://www.rfc-editor.org/rfc/rfc959).
The network communication will be achieved through the use of TCP sockets.

## Usage


```bash
$> make re
[...]
./myftp [port] [root_path]
        port  is the port number on which the server socket listens
        root_path  is the root_path to the home directory for the Anonymous user
```

### Launch tests

```bash
$> make tests_run
[...]
```

### Debug mode

```bash
$> make fclean && make debug
[...]
$> valgrind --leak-check=full --show-leak-kinds=all -s ./myftp [port] [root_path]
```

## FTP Commands

The following is a list of commands available on the FTP server:

| Command                         | Description                                  | Return Code                         |
|---------------------------------|----------------------------------------------|-------------------------------------|
| Connection Establishment        |                                              | `<- 220`                            |
| Login                           |                                              |                                     |
| `USER <SP> <username> <CRLF>`   | Specify user for authentication              | `<- 230` `<- xxx` `<- 331`          |
| `PASS <SP> <password> <CRLF>`   | Specify password for authentication          | `<- 230` `<- 332` `<- xxx`          |
| `CWD <SP> <pathname> <CRLF>`    | Change working directory                     | `<- 250` `<- xxx`                   |
| `CDUP <CRLF>`                   | Change working directory to parent directory | `<- 200` `<- xxx`                   |
| Logout                          |                                              |                                     |
| `QUIT <CRLF>`                   | Disconnection                                | `<- 221` `<- xxx`                   |
| Transfer parameters             |                                              |                                     |
| `PORT <SP> <host-port> <CRLF>`  | Enable "active" mode for data transfer       | `<- 200` `<- xxx`                   |
| `PASV <CRLF>`                   | Enable "passive" mode for data transfer      | `<- 227` `<- xxx`                   |
| File action commands            |                                              |                                     |
| `STOR <SP> <pathname> <CRLF>`   | Upload file from client to server            | `<- 150` `<- 226` `<- xxx` `<- xxx` |
| `RETR <SP> <pathname> <CRLF>`   | Download file from server to client          | `<- 150` `<- 226` `<- xxx` `<- xxx` |
| `LIST [<SP> <pathname>] <CRLF>` | List files in the current working directory  | `<- 150` `<- 226` `<- xxx` `<- xxx` |
| `DELE <SP> <pathname> <CRLF>`   | Delete file on the server                    | `<- 250` `<- xxx`                   |
| `PWD <CRLF>`                    | Print working directory                      | `<- 257` `<- xxx`                   |
| Informational commands          |                                              |                                     |
| `HELP [<SP> <string>] <CRLF>`   | List available commands                      | `<- 214` `<- xxx`                   |
| Miscellaneous commands          |                                              |                                     |
| `NOOP <CRLF>`                   | Do nothing                                   | `<- 200` `<- xxx`                   |

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
