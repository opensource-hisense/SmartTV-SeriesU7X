/*
 * Copyright (C) 2005 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Android config -- "android-arm".  Used for ARM device builds.
 */
#ifndef _ANDROID_CONFIG_H
#define _ANDROID_CONFIG_H

/*
 * ===========================================================================
 *                              !!! IMPORTANT !!!
 * ===========================================================================
 *
 * This file is included by ALL C/C++ source files.  Don't put anything in
 * here unless you are absolutely certain it can't go anywhere else.
 *
 * Any C++ stuff must be wrapped with "#ifdef __cplusplus".  Do not use "//"
 * comments.
 */

/*
 * Threading model.  Choose one:
 *
 * HAVE_PTHREADS - use the pthreads library.
 * HAVE_WIN32_THREADS - use Win32 thread primitives.
 *  -- combine HAVE_CREATETHREAD, HAVE_CREATEMUTEX, and HAVE__BEGINTHREADEX
 */
#define HAVE_PTHREADS

/*
 * Do we have pthread_setname_np()?
 *
 * (HAVE_PTHREAD_SETNAME_NP is used by WebKit to enable a function with
 * the same name but different parameters, so we can't use that here.)
 */
#define HAVE_ANDROID_PTHREAD_SETNAME_NP

/*
 * Do we have the futex syscall?
 */
#define HAVE_FUTEX

/*
 * Process creation model.  Choose one:
 *
 * HAVE_FORKEXEC - use fork() and exec()
 * HAVE_WIN32_PROC - use CreateProcess()
 */
#define HAVE_FORKEXEC

/*
 * IPC model.  Choose one:
 *
 * HAVE_SYSV_IPC - use the classic SysV IPC mechanisms (semget, shmget).
 * HAVE_MACOSX_IPC - use Macintosh IPC mechanisms (sem_open, mmap).
 * HAVE_WIN32_IPC - use Win32 IPC (CreateSemaphore, CreateFileMapping).
 * HAVE_ANDROID_IPC - use Android versions (?, mmap).
 */
#define HAVE_ANDROID_IPC

/*
 * Memory-mapping model. Choose one:
 *
 * HAVE_POSIX_FILEMAP - use the Posix sys/mmap.h
 * HAVE_WIN32_FILEMAP - use Win32 filemaps
 */
#define  HAVE_POSIX_FILEMAP

/*
 * Define this if you have <termio.h>
 */
#define  HAVE_TERMIO_H 1

/*
 * Define this if you have <sys/sendfile.h>
 */
#define  HAVE_SYS_SENDFILE_H 1

/*
 * Define this if you build against MSVCRT.DLL
 */
/* #define HAVE_MS_C_RUNTIME */

/*
 * Define this if you have sys/uio.h
 */
#define  HAVE_SYS_UIO_H 1

/*
 * Define this if your platforms implements symbolic links
 * in its filesystems
 */
#define HAVE_SYMLINKS

/*
 * Define this if we have localtime_r().
 */
/* #define HAVE_LOCALTIME_R 1 */

/*
 * Define this if we have gethostbyname_r().
 */
/* #define HAVE_GETHOSTBYNAME_R */

/*
 * Define this if we have ioctl().
 */
#define HAVE_IOCTL

/*
 * Define this if we want to use WinSock.
 */
/* #define HAVE_WINSOCK */

/*
 * Define this if have clock_gettime() and friends
 */
#define HAVE_POSIX_CLOCKS

/*
 * Define this if we have linux style epoll()
 */
#define HAVE_EPOLL

/*
 * Endianness of the target machine.  Choose one:
 *
 * HAVE_ENDIAN_H -- have endian.h header we can include.
 * HAVE_LITTLE_ENDIAN -- we are little endian.
 * HAVE_BIG_ENDIAN -- we are big endian.
 */
#define HAVE_ENDIAN_H
#define HAVE_LITTLE_ENDIAN

/*
 * We need to choose between 32-bit and 64-bit off_t.  All of our code should
 * agree on the same size.  For desktop systems, use 64-bit values,
 * because some of our libraries (e.g. wxWidgets) expect to be built that way.
 */
/* #define _FILE_OFFSET_BITS 64 */
/* #define _LARGEFILE_SOURCE 1 */

/*
 * Define if platform has off64_t (and lseek64 and other xxx64 functions)
 */
#define HAVE_OFF64_T

/*
 * Defined if we have the backtrace() call for retrieving a stack trace.
 * Needed for CallStack to operate; if not defined, CallStack is
 * non-functional.
 */
#define HAVE_BACKTRACE 0

/*
 * Defined if we have the cxxabi.h header for demangling C++ symbols.  If
 * not defined, stack crawls will be displayed with raw mangled symbols
 */
#define HAVE_CXXABI 0

/*
 * Defined if we have the gettid() system call.
 */
#define HAVE_GETTID    // STDLIBC_INTEGER

/*
 * Defined if we have the sched_setscheduler() call
 */
#define HAVE_SCHED_SETSCHEDULER

/*
 * Add any extra platform-specific defines here.
 */
#ifndef __linux__
#define __linux__
#endif

#ifndef __ANDROID__
#define __ANDROID__
#endif //Add to enable __ANDROID__ define

/*
 * Define if we have <malloc.h> header
 */
#define HAVE_MALLOC_H

/*
 * Define if we're running on *our* linux on device or emulator.
 */
#define HAVE_ANDROID_OS 1

/*
 * Define if we have Linux-style non-filesystem Unix Domain Sockets
 */
#define HAVE_LINUX_LOCAL_SOCKET_NAMESPACE 1

/*
 * Define if we have Linux's inotify in <sys/inotify.h>.
 */
#define HAVE_INOTIFY 1

/*
 * Define if we have madvise() in <sys/mman.h>
 */
#define HAVE_MADVISE 1

/*
 * Define if tm struct has tm_gmtoff field
 */
#define HAVE_TM_GMTOFF 1

/*
 * Define if dirent struct has d_type field
 */
#define HAVE_DIRENT_D_TYPE 1

/*
 * Define if libc includes Android system properties implementation.
 */
#define HAVE_LIBC_SYSTEM_PROPERTIES 1

/*
 * Define if system provides a system property server (should be
 * mutually exclusive with HAVE_LIBC_SYSTEM_PROPERTIES).
 */
/* #define HAVE_SYSTEM_PROPERTY_SERVER */

/*
 * What CPU architecture does this platform use?
 */
//STDLIBC_INTEGER START
//#define ARCH_ARM
//STDLIBC_INTEGER START
#define CHRE_ASSERTIONS_DISABLED
// referece from system/chre/Makefile
//STDLIBC_INTEGER START
#define CHRE_MINIMUM_LOG_LEVEL CHRE_LOG_LEVEL_DEBUG
// reference from system/chre/Makefile

//STDLIBC_INTEGER START
/*
 * Define if the size of enums is as short as possible,
 */
/* #define HAVE_SHORT_ENUMS */

/*
 * sprintf() format string for shared library naming.
 */
#define OS_SHARED_LIB_FORMAT_STR    "lib%s.so"

/*
 * type for the third argument to mincore().
 */
#define MINCORE_POINTER_TYPE unsigned char *

/*
 * The default path separator for the platform
 */
#define OS_PATH_SEPARATOR '/'

/*
 * Is the filesystem case sensitive?
 */
#define OS_CASE_SENSITIVE

/*
 * Define if <sys/socket.h> exists.
 */
#define HAVE_SYS_SOCKET_H 1

/*
 * Define if the strlcpy() function exists on the system.
 */
/* #define HAVE_STRLCPY 1 */ // STDLIBC_INTEGER

/*
 * Define if the open_memstream() function exists on the system.
 */
/* #define HAVE_OPEN_MEMSTREAM 1 */

/*
 * Define if the BSD funopen() function exists on the system.
 */
#define HAVE_FUNOPEN 1

/*
 * Define if prctl() exists
 */
#define HAVE_PRCTL 1

/*
 * Define if writev() exists
 */
#define HAVE_WRITEV 1

/*
 * Define if <stdint.h> exists.
 */
#define HAVE_STDINT_H 1

/*
 * Define if <stdbool.h> exists.
 */
#define HAVE_STDBOOL_H 1

/*
 * Define if <sched.h> exists.
 */
#define HAVE_SCHED_H 1

/*
 * Define if pread() exists
 */
#define HAVE_PREAD 1

/*
 * Define if we have st_mtim in struct stat
 */
#define HAVE_STAT_ST_MTIM 1

/*
 * Define if printf() supports %zd for size_t arguments
 */
#define HAVE_PRINTF_ZD 1

/*
 * Define to 1 if <stdlib.h> provides qsort_r() with a BSD style function prototype.
 */
#define HAVE_BSD_QSORT_R 0

/*
 * Define to 1 if <stdlib.h> provides qsort_r() with a GNU style function prototype.
 */
#define HAVE_GNU_QSORT_R 0

#define HAVE_CONFIG_H 1
#define USE_PCRE2 1

//Notice ,After 11  
#define __ANDROID_VNDK__ 1
#endif /* _ANDROID_CONFIG_H */
