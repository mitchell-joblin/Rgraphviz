#ifndef __COMMON_H_INCLUDED
#define __COMMON_H_INCLUDED

#define DOTLAYOUT 0
#define NEATOLAYOUT 1
#define TWOPILAYOUT 2
#define CIRCOLAYOUT 3
#define FDPLAYOUT 4

#define MINGRAPHVIZVER "1.9.20030423.0415"

#define ENABLE_CODEGENS 1

#include <Rinternals.h>
#include <Rdefines.h>
#include <Rmath.h>
#include <R_ext/RConverters.h>
#include <R_ext/Rdynload.h>
#ifndef WIN32
#include <unistd.h>
#endif

#include <math.h>

#ifdef GRAPHVIZGT_2_4
#include <gvc.h>
#include <gvplugin.h>
#include <gvcext.h>
#include <gvcint.h>
#include <globals.h>
#else
#include <render.h>
#include <graph.h>
#include <dotprocs.h>
#include <neatoprocs.h>
#include <adjust.h>
#include <renderprocs.h>
#endif

/*#include <gvrender.h> */

#ifndef GRAPHVIZGT_2_4
extern char *Info[];
#endif

static GVC_t *gvc;

#define AGRAPH_T(x) ((agraph_t *)DATAPTR(x))
#define STR(SE) CHAR(STRING_ELT(SE,0))

SEXP Rgraphviz_init(void);
SEXP Rgraphviz_doLayout(SEXP, SEXP);
SEXP Rgraphviz_agread(SEXP);
SEXP Rgraphviz_agwrite(SEXP, SEXP);
SEXP Rgraphviz_agopen(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
SEXP Rgraphviz_graphvizVersion(void);
SEXP Rgraphviz_bezier(SEXP, SEXP, SEXP);
SEXP Rgraphviz_buildNodeList(SEXP, SEXP, SEXP, SEXP);
SEXP Rgraphviz_buildEdgeList(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
SEXP generatePNodes(SEXP, SEXP);

#endif
