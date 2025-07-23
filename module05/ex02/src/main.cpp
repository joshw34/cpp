#include "../inc/Colors.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

int main() {
    Bureaucrat dave("BigDave", 79);
    AForm form("256B", 100, 80);

    dave.signForm(form);
    return 0;
}
