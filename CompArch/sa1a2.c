int main()
{
    char *string, *reverse_string;
    int i, length = 0, flag = 0;
 
    string = "abba"; 
    /*  keep going through each character of the string till its end */
    for (i = 0; string[i] != '\0'; i++)
    {
        length++;
    }
    for (i = length - 1; i >= 0 ; i--)
    {
        reverse_string[length - i - 1] = string[i];
    }
   /*  Check if the string is a Palindrome */
 
    for (flag = 1, i = 0; i < length ; i++)
    {
        if (reverse_string[i] != string[i])
            flag = 0;
    }
}
