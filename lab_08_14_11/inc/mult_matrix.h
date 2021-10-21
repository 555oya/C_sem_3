void mult_matrix(double **a, double **b, double **ab, size_t m, size_t n);
void add_matrix(double **a, double **b, double **ab, size_t m, size_t n);
void move_row(double **a, size_t m, size_t elem_i);
int find_main_element(double **a, size_t m);
int check_echelon_form(double **a, size_t m);
int row_echelon_form(double **a, size_t m);
int inverse_matrix(double **a, size_t m);
