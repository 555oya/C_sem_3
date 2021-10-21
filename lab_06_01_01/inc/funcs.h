#define MAX_STR_SIZE 26
#define MAX_SUBSTANCE_NUM 15

struct substance
{
    char name[MAX_STR_SIZE];
    double mass;
    double volume;
};

size_t is_matching(char *name_str, const char *prefix);

double get_density(double mass, double volume);

void insert_element(struct substance item[], char *name_str, double mass, double volume, size_t count);

void name(struct substance *item, size_t count);

void print_whole_list(struct substance *item, size_t count);

size_t print_search_list(struct substance *item, size_t count, const char *prefix);
