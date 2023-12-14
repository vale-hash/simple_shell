/**
 *_strcpy - function to copy one string to another
 * @dest: the destination string
 * @src: the sourc string
 * Return: returns the copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] =  src[i];

		dest[i + 1] = '\0';
	}
	return (dest);
}
