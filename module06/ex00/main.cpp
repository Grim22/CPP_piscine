#include "iostream"
#include "cctype" // is_print, is_digit...
#include "sstream" // stringstreams
#include "limits" // int limits
#include "iomanip" // fiels manipulators (set_precision...)

#define INT 0
#define CHAR 1
#define FLOAT 2
#define DOUBLE 3
#define INVALID 4
#define OTHER 5 //inf, nan

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
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl; // if more than float_max will display inf (or -inf) --> no need to use numeric limits

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
    if (f < 0 || f > std::numeric_limits<char>::max()) // numeric limit will be (implicitly) promoted to float before comparison is made
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

void input_is_other(char *argv)
{
    std::string arg(argv);
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (arg == "nan" || arg == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    if (arg == "+inf" || arg == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    if (arg == "-inf" || arg == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
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
    std::cout << std::fixed << std::setprecision(1); // when "fixed" is set, the number of numbers after decimal point will always be the same. It is set with "setprecision"
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

int detect_type(char *argv1)
{
    std::string arg;
    arg = argv1;
    if (arg.size() == 1 && std::isprint(arg[0]) && !std::isdigit(arg[0]))
        return CHAR;

    if (arg == "-inf" || arg == "nan" || arg == "+inf")
        return OTHER;
    if (arg == "-inff" || arg == "nanf" || arg == "+inff")
        return OTHER;
    
    if (arg[0] == '-')
        arg = arg.substr(1);
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

    if (type == INT)
        input_is_int(argv[1]);
    else if (type == CHAR)
        input_is_char(argv[1]);
    else if (type == FLOAT)
        input_is_float(argv[1]);
    else if (type == DOUBLE)
        input_is_double(argv[1]);
    else if (type == OTHER)
        input_is_other(argv[1]);
}