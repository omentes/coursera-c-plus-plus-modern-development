//
// Created by omentes on 11.10.20.
//

int	Factorial(int number)
{
    if (number > 10 || number < 0)
        return 1;
    if (number == 0)
        return 1;
    else
        return number * Factorial(number - 1);
}
