#include "tree.h"

std::ostream& operator << ( std::ostream& stream, const tree& t )
{
    stream << t.functor() << " [ " << t.getaddress() << " ] " << std::endl;

    if(t.nrsubtrees() != 0)
    {
        for(size_t i = 0; i < t.nrsubtrees(); i++)
        {
            stream << t[i];
        }
    }
    return stream;
}

void tree::replacesubtree(size_t i, const tree& t)
{
    if(pntr->subtrees[i].pntr != t.pntr)
    {
        ensure_not_shared();
        pntr->subtrees[i] = t;
    }
}

tree subst(const tree& t, const string& var, const tree& val)
{
    if(t.nrsubtrees() == 0)
    {
        if(t.functor() == var)
            return val;
        return t;
    }

    tree temp = t;

    for(size_t i = 0; i < t.nrsubtrees(); i++)
    {
        temp.replacesubtree(i, subst(temp[i], var, val));
    }

    return temp;

}
void tree::replacefunctor(const string& f)
{
    if(pntr->f != f)
    {
        ensure_not_shared();
        pntr->f = f;
    }
}
