/*-------------------------------------------------------------------------
 *
 * makefuncs.h
 *	  prototypes for the creator functions (for primitive nodes)
 *
 *
 * Portions Copyright (c) 1996-2009, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/nodes/makefuncs.h,v 1.61 2008/01/01 19:45:58 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef MAKEFUNC_H
#define MAKEFUNC_H

#include "nodes/parsenodes.h"


extern A_Expr *makeA_Expr(A_Expr_Kind kind, List *name,
		   Node *lexpr, Node *rexpr, int location);

extern A_Expr *makeSimpleA_Expr(A_Expr_Kind kind, const char *name,
				 Node *lexpr, Node *rexpr, int location);

extern Var *makeVar(Index varno,
		AttrNumber varattno,
		Oid vartype,
		int32 vartypmod,
		Index varlevelsup);

extern TargetEntry *makeTargetEntry(Expr *expr,
				AttrNumber resno,
				char *resname,
				bool resjunk);

extern TargetEntry *flatCopyTargetEntry(TargetEntry *src_tle);

extern FromExpr *makeFromExpr(List *fromlist, Node *quals);

extern Const *makeConst(Oid consttype,
		  int32 consttypmod,
		  int constlen,
		  Datum constvalue,
		  bool constisnull,
		  bool constbyval);

extern Const *makeNullConst(Oid consttype, int32 consttypmod);

extern Node *makeBoolConst(bool value, bool isnull);

extern Expr *makeBoolExpr(BoolExprType boolop, List *args, int location);

extern Alias *makeAlias(const char *aliasname, List *colnames);

extern RelabelType *makeRelabelType(Expr *arg, Oid rtype, int32 rtypmod,
				CoercionForm rformat);

extern RangeVar *makeRangeVar(char *schemaname, char *relname, int location);

extern TypeName *makeTypeName(char *typnam);
extern TypeName *makeTypeNameFromNameList(List *names);
extern TypeName *makeTypeNameFromOid(Oid typid, int32 typmod);

extern FuncExpr *makeFuncExpr(Oid funcid, Oid rettype,
			 List *args, CoercionForm fformat);

extern DefElem *makeDefElem(char *name, Node *arg);
extern Aggref *makeAggrefByOid(Oid aggfnoid, List *args);

#endif   /* MAKEFUNC_H */
