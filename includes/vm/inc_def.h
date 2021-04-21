/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_def.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:07:49 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/15 10:59:58 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_DEF_H
# define INC_DEF_H

# include "op.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <ctype.h>
# include <ncurses.h>

# define OPT_D "-d"
# define OPT_N "-n"
# define OPT_A "-a"
# define OPT_V "-v"
# define OPT_S "-s"
# define OPT_B "-b"
# define OPT_F "-f"

# define USG0 "Usage: corewar [-d N] [-s | -b N | -f] [-v] [-a] [-n N] "
# define USG1 "<champion.cor> <...>\n	"
# define USG2 "-a	: Prints output from 'aff' (Default is to hide it)"
# define USG3 "**** TEXT OUTPUT MODE ******************************************"
# define USG4 "	-d N	: Dumps memory after N cycles then exits"
# define USG5 "	-f	: Flow of debug"
# define USG6 "	-b N	: Debug mode from N cycles"
# define USG7 "	-s	: Debug 'step-by-step' mode"
# define USG8 "**** NCURSES OUTPUT MODE ***************************************"
# define USG9 "	-v	: Ncurses output mode"
# define NON_V "Too small window of terminal. Sorry!\nRun non-visual mode:\n\n"
# define MSG_INTRO "Introducing contestants...\n"

# define ERR_NUM_PL_EXISTS "Player with this number already exist"
# define ERR_NUM_PL_CANT "Player with such number cannot exist"
# define ERR_MALLOC_STRUCTURE "Problem with malloc for structure"
# define ERR_MALLOC_ARENA "Problem with malloc for arena"
# define ERR_MALLOC_FIELD "Problem with malloc for field"
# define ERR_MALLOC_VISUAL "Problem with malloc for visual mode"
# define ERR_MALLOC_CURSOR "Problem with malloc for carriage"
# define ERR_MALLOC_PLAYER "Problem with malloc for player"
# define ERR_MALLOC_CODE "Problem with malloc for player code"
# define ERR_MALLOC_NAME "Problem with malloc for name/comment of champ"
# define ERR_MALLOC_BUFFER "Problem with malloc for buffer or magic number"
# define ERR_BIG_CODE "Too long code"
# define ERR_END_FILE "Something wrong with end of file"
# define ERR_READ_EOF "File unexpectedly ended while reading size of a champion"
# define ERR_NM_EOF "Unexpected end of file while reading name/comment of champ"
# define ERR_NUL_EOF "Unexpected end of file while reading MAGIC HEADER or NULL"
# define ERR_MAGIC "Wrong MAGIC HEADER"
# define ERR_NULL "Wrong NULL"
# define ERR_OPEN "File does not open"
# define ERR_CLOSE "File does not close"
# define ERR_COUNT_PL "Too much players"
# define ERR_COUNT_PARAM "Wrong number of parameters"
# define ERR_CYCLE_OPT "Wrong cycle number"

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define SIZE_MAGIC_NULL 4
# define COLUMNS 64

# define MAX_COLOR_PL 4

# define A1 "Cycles:       "
# define A2 "Alive:        "
# define A3 "nbr_live:     "
# define A4 "Cycle_to_die: "
# define A9 "Operation:    "
# define A5 "ID of cursor: "
# define A6 "pc of cursor: "
# define A7 "last_live:    "
# define A8 "Registrs:     "
# define A10 "Arguments:    "
# define A11 "Arg1:         "
# define A12 "Arg2:         "
# define A13 "Arg3:         "
# define A21 "\n"
# define A22 "---"
# define A23 "REG"
# define A24 "DIR"
# define A25 "IND"
# define A26 " | "
# define A27 "Action:       "
# define A30 "Press enter to continue ↵\n"

#endif
