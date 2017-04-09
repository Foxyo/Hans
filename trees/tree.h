
#ifndef TREE_INCLUDED
#define TREE_INCLUDED  1


#include <iostream>
#include <vector>
#include "string.h"

class tree;

struct trnode
{
   string f;
   std::vector<tree> subtrees;

   size_t refcnt;

   trnode(const string& f, const std::vector<tree> & subtrees size_t refcnt )
      : f{f},
        subtrees{subtrees},
        refcnt{refcnt}
   { }

   trnode( const string& f, std::vector< tree > && subtrees,
           size_t refcnt )
      : f{f},
        subtrees{ std::move( subtrees )},
        refcnt{ refcnt }
   { }

};


class tree
{
   trnode* pntr;

public:
   tree( const string& f )
      : pntr( new trnode( f, { }, 1 ))
   { }

   tree( const string& f, const std::vector< tree > & subtrees )
      : pntr( new trnode( f, subtrees, 1 ))
   { }

   tree( const string& f, std::vector< tree > && subtrees )
      : pntr( new trnode( f, std::move( subtrees ), 1 ))
   { }


   tree( const tree& t ) : pntr(t.pntr) {pntr->refcnt++;}
      // There is no need to write tree( tree&& t ),
      // because we cannot improve.

   void operator = ( tree&& t )
   {
     std::swap(pntr, t.pntr);
     /*pntr = std::move(t.pntr);
     return *this;*/
   }
   void operator = ( const tree& t )
   {
    *this = tree(t);
   }

   const string& functor( ) const
   {
       return pntr->f;
   }

   const tree& operator [ ] ( size_t i ) const
   {
       return pntr->subtrees[i];
   }

   size_t nrsubtrees( ) const
   {
       return pntr->subtrees.size();
   }

   ~tree( )
   {
     pntr->refcnt--;
     if(pntr->refcnt == 0)
        delete pntr;
   }

   void replacesubtree(size_t i, const tree& t);
   void replacefunctor(const string& f);
   size_t getaddress( ) const
   {
    return reinterpret_cast< size_t > ( pntr );
   }

private:

   void ensure_not_shared( )
   {
       if(pntr->refcnt != 1)
       {
           pntr->refcnt--;
           pntr = new trnode(pntr->f, pntr->subtrees, 1);
       }
   }



};

std::ostream& operator << ( std::ostream& stream, const tree& t );

tree subst(const tree& t, const string& var, const tree& val);
   // Doesn't need to be friend, because it uses only functor( ),
   // nrsubtrees( ) and [ ].

#endif
