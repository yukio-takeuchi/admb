/*
 * $Id$
 *
 * Author: David Fournier
 * Copyright (c) 2008-2012 Regents of the University of California
 */
#include "fvar.hpp"

/**
Reallocate size of array.

\param percent change
*/
void ivector::reallocate(double s)
{
  if (::allocated(*this))
  {
    int oldmin=indexmin();
    int oldmax=indexmax();
    ivector tmp(indexmin(),indexmax());
    tmp=(*this);
    deallocate();
    allocate(indexmin(),int(s*indexmax()));
    (*this)(oldmin,oldmax)=tmp;
  }
}
