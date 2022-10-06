#include <vector>
#include <map>
using std::map;
using std::vector;

enum Actions {MULTIPLY, ADD, MINUS, DIVIDE_SAVE, DIVIDE_PRECISE, MOD, SQUARE_ROOT, POWER};

struct nice_number
{
    bool valid;
    bool positive;
    vector<char> critical;
    long long exponential;
};

struct operation
{
    Actions action;
    int level;
    int rank;
};

nice_number add(nice_number first_number, nice_number second_number);

nice_number multiply(nice_number first_number, nice_number second_number);

nice_number minus(nice_number first_number, nice_number second_number);

nice_number dividePrecise(nice_number first_number, nice_number second_number);

nice_number divideSave(nice_number first_number, nice_number second_number);

nice_number mod(nice_number first_number, nice_number second_number);

nice_number squareRoot(nice_number first_number, nice_number second_number);

nice_number power(nice_number first_number, nice_number second_number);

void calculate(vector<vector<char>> input_stream, map<string,nice_number> variable_map);