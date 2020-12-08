#include "typeinfo"
#include "iostream"
#include "cctype"
#include "cstdlib"
#include "sstream"
#include "limits"
#include "iomanip"

#define INT 0
#define CHAR 1
#define FLOAT 2
#define DOUBLE 3
#define INVALID 4

int count_dec(char *argv1)
{
    std::string arg;
    arg = argv1;

    unsigned long dec_point_pos;
    dec_point_pos = arg.find('.');
    std::string fract_part = arg.substr(dec_point_pos + 1);
    if (fract_part[fract_part.size() - 1] == 'f')
        fract_part.erase(fract_part.size() - 1);
    return fract_part.size();
}    

bool is_int_str(std::string arg)
{
    if (arg.size() == 0)
        return false;
    for (size_t i = 0; i < arg.size(); i++)
    {
        if (!isdigit(arg[i]))
            return false;
    }
    return true;
}

void input_is_double(char *argv)
{
    double d;
    int num_dec;
    num_dec = count_dec(argv);
    std::stringstream ss;
    ss << argv;
    ss.exceptions(std::istream::failbit); // if failbit is set, make object throw an exception (of type ios_base::failure, which inherits from std::exception)
    try
    {
        ss >> d;
    }
    catch(const std::exception& e)
    {
        (void)e;
        std::cerr << "value is out of range" << std::endl;
        return;
    }

    if (d < 0 || d > std::numeric_limits<char>::max()) // all will be (implicitly) promoted to float before comparison is made
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(d))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    if (d <= std::numeric_limits<int>::min() || d >= std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    
    std::cout << std::fixed << std::setprecision(num_dec);
    if (d >= std::numeric_limits<float>::max() || d <= -std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

    std::cout << "double: " << d << std::endl;
}
void input_is_float(char *argv)
{
    float f;
    int num_dec;
    num_dec = count_dec(argv);
    std::stringstream ss;
    ss << argv;
    ss.exceptions(std::istream::failbit); // if failbit is set, make object throw an exception (of type ios_base::failure, which inherits from std::exception)
    try
    {
        ss >> f;
    }
    catch(const std::exception& e)
    {
        (void)e;
        std::cerr << "value is out of range" << std::endl;
        return;
    }

    if (f < 0 || f > std::numeric_limits<char>::max()) // all will be (implicitly) promoted to float before comparison is made
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(f))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    if (f <= std::numeric_limits<int>::min() || f >= std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    
    std::cout << std::fixed << std::setprecision(num_dec);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void input_is_char(char *argv)
{
    char c;
    std::stringstream ss;
    ss << argv;
    ss >> c; // no overflow possible if "char" was selected
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void input_is_int(char *argv)
{        
    std::stringstream ss;
    int i;
    ss << argv;
    ss.exceptions(std::istream::failbit); // if failbit is set, make object throw an exception (of type ios_base::failure, which inherits from std::exception)
    try
    {
        ss >> i;
    }
    catch(const std::exception& e)
    {
        (void)e;
        std::cerr << "value is out of range" << std::endl;
        return;
    }

    if (i < 0 || i > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(i))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

int detect_type(char *argv1)
{
    std::string arg;
    arg = argv1;
    if (arg.size() == 1 && std::isprint(arg[0]) && !std::isdigit(arg[0]))
        return CHAR;

    if (arg == "-inf" || arg == "nan" || arg == "+inf")
        return DOUBLE;
    if (arg == "-inff" || arg == "nanf" || arg == "+inff")
        return FLOAT;
    
    if (arg[0] == '-')
        arg = arg.substr(1);
    //std::cout << arg << std::endl;
    if (is_int_str(arg) == true)
        return INT;
    
    unsigned long dec_point_pos;
    bool floating_point = false;
    if ((dec_point_pos = arg.find('.')) != std::string::npos)
    {
        std::string dec_part = arg.substr(0, dec_point_pos);
        std::string fract_part = arg.substr(dec_point_pos + 1);
        if (fract_part[fract_part.size() - 1] == 'f')
        {
            floating_point = true;
            fract_part.erase(fract_part.size() - 1);
        }
        //std::cout <<"dec part: " << dec_part << std::endl;
        //std::cout << "fract part: " << fract_part << std::endl;
        if (is_int_str(dec_part) && is_int_str(fract_part))
        {
            if (floating_point)
                return FLOAT;
            else
                return DOUBLE;
        }
    }
    
    return INVALID;    
}

int main(int argc, char **argv)
{
    // float a;
    // double b;
    // int c;
    // char d;
    // float y = 42;
    // a = static_cast<float>(*x);
    // c = static_cast<int>(*x);
    // b = static_cast<double>(*x);
    // d = static_cast<char>(*x);
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << c << std::endl;
    // std::cout << d << std::endl;

    if (argc == 1 || argc > 2)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        return 0;
    }

    int type;
    type = detect_type(argv[1]);
    if (type == INVALID)
    {
        std::cerr << "Litteral value not char or int or float or double" << std::endl;
        return 0;
    }
    std::cout << type << std::endl;

    if (type == INT)
        input_is_int(argv[1]);
    else if (type == CHAR)
        input_is_char(argv[1]);
    else if (type == FLOAT)
        input_is_float(argv[1]);
    else if (type == DOUBLE)
        input_is_double(argv[1]);
    // if (arg.size() == 1)
}