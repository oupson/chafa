/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/* Copyright (C) 2020-2024 Hans Petter Jansson
 *
 * This file is part of Chafa, a program that shows pictures on text terminals.
 *
 * Chafa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Chafa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Chafa.  If not, see <http://www.gnu.org/licenses/>. */

#define CHAFA_TERM_SEQ_DEF(name, NAME, n_args, arg_proc, arg_type, ...)  \
    gchar *chafa_term_info_emit_##name (const ChafaTermInfo *term_info, gchar *dest __VA_ARGS__);
#define CHAFA_TERM_SEQ_DEF_VARARGS(name, NAME, arg_type)  \
    gchar * chafa_term_info_emit_##name(const ChafaTermInfo *term_info, gchar *dest, arg_type *args, gint n_args);
#include "chafa-term-seq-def.h"
#undef CHAFA_TERM_SEQ_DEF
#undef CHAFA_TERM_SEQ_DEF_VARARGS

typedef enum
{
#define CHAFA_TERM_SEQ_DEF(name, NAME, n_args, arg_proc, arg_type, ...) CHAFA_TERM_SEQ_##NAME,
#define CHAFA_TERM_SEQ_DEF_VARARGS(name, NAME, arg_type) CHAFA_TERM_SEQ_##NAME,
#include "chafa-term-seq-def.h"
#undef CHAFA_TERM_SEQ_DEF
#undef CHAFA_TERM_SEQ_DEF_VARARGS

    CHAFA_TERM_SEQ_MAX
}
ChafaTermSeq;
