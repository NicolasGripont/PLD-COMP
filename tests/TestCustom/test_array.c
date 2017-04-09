void main()
{
    int32_t test[7];

    test[2] = 't';
    test[1] = 'a';
    test[4] = 'b';
    test[6] = 'l';

    putchar(test[1]); // Doit donner 'a'

    char dodo = test[6] + 1; 
    putchar(dodo); // Doit donner 'l'+1 soit 'm'

    test[6] = 't';
    putchar(test[6]+4); // Doit donner 't'+4 soit 'x'

    char toto[4];
    toto[0] = 'h' + 3; 
    putchar(toto[0]); // Doit donner 'k'

    putchar(toto[5]); // Potentiellement foireux donne rien ou n'importe quoi

    putchar('\n');
}
