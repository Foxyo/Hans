#include "fifteen.h"


fifteen::fifteen() : open_i{dimension-1}, open_j{dimension-1}
{
    for(size_t i = 0; i < dimension; ++i)
    {
            for(size_t j = 0; j < dimension; ++j)
                table[i][j] = dimension*i + j+1;
    }
    table[dimension-1][dimension-1] = 0;
}

fifteen::fifteen(std::initializer_list<std::initializer_list<size_t>> init_l)
{
    size_t i = 0, j = 0;

    for(auto it_i = init_l.begin(); i < dimension && it_i != init_l.end(); ++i, ++it_i)
    {
        j = 0;

        for(auto it_j = (*it_i).begin(); j < dimension && it_j != (*it_i).end(); ++j, ++it_j)
        {
            table[i][j] = *it_j;

            if(*it_j == 0)
            open_i = i, open_j = j;
        }
    }
}

std::ostream& operator << (std::ostream& stream, const fifteen& puzzle)
{
    for(size_t i = 0; i < puzzle.dimension; ++i)
    {
        for(size_t j = 0; j < puzzle.dimension; ++j)
            stream << puzzle.table[i][j] << "\t";

        stream << "\n";
    }
    return stream;
}

std::pair<size_t, size_t> fifteen::solvedposition(size_t val)
{
    //std::cout << "test solvedpos";
    std::pair<size_t, size_t> _pair = std::make_pair((val-1)/dimension, (val-1) % dimension);
    if(val == 0)
    _pair = std::make_pair(dimension-1, dimension-1);
    return _pair;
}

/*size_t fifteen::hashvalue() const
{
    //std::cout << "test hashval";
    size_t hashval = 0;

    for(size_t i = 0; i < dimension; ++i)
    {
        for(size_t j = 0; j < dimension; ++j)
        {
            hashval *= ((i+7) * 17 + (j+5) * 61) * (i+j+257);
        }
    }
    return hashval;
}*/
size_t fifteen::hashvalue( ) const
{
        size_t w = 97;
        //const size_t MOD = 1000000007;

        for(size_t i = 0; i < dimension; ++i)
        {
                for(size_t j = 0; j < dimension; ++j)
                {
					w *= ((i+7) * 17 + (j+5) * 61) * (i+j+257);

                }
        }

        return w;
}


bool fifteen::equals(const fifteen& diff_table) const
{
    //std::cout << "test equals";
    for(size_t i = 0; i < dimension; ++i)
    {
        for(size_t j = 0; j < dimension; ++j)
        {
            if(table[i][j] != diff_table.table[i][j])
                return false;
        }
    }
    return true;
}

size_t fifteen::distance() const
{
    //std::cout << "test distance";
    size_t _distance = 0;

    for(size_t i = 0; i < dimension; ++i)
    {
        for(size_t j = 0; j < dimension; ++j)
        {
            auto _pair = solvedposition(table[i][j]);

            _distance += distance(_pair, {i,j});
        }
    }

    return _distance;
}

bool fifteen::issolved() const
{
    //std::cout << "test issolved";
    return distance() == 0;
}

void fifteen::makemove(move p)
{
 	switch (p)
	{
    	case move::left:
      		if (open_j == 0)
				throw illegalmove(p);
      		else {
        		std::swap(table[open_i][open_j], table[open_i][open_j-1]);
        		open_j -= 1;
      		}
      		break;
    	case move::up:
	      	if (open_i == 0)
				throw illegalmove(p);
	      	else {
	        	std::swap(table[open_i][open_j], table[open_i-1][open_j]);
	        	open_i -= 1;
	      	}
	      	break;
    	case move::down:
	    	if (open_i == dimension-1)
		  		throw illegalmove(p);
	      	else {
			  std::swap(table[open_i][open_j], table[open_i+1][open_j]);
			  open_i += 1;
	      	}
	      break;
    	case move::right:
      		if (open_j == dimension-1)
				throw illegalmove(p);
      		else {
        		std::swap(table[open_i][open_j], table[open_i][open_j+1]);
        		open_j += 1;
      		}
      	break;
  	}

}
