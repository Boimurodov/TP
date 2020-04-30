header_name = "index.h"
code = """
bool A_checker()
{
    return true;
}
"""

f = open(header_name, "w")
f.write(code)
f.close()
