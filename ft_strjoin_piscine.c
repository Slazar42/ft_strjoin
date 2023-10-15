#include<stdio.h>
#include<stdlib.h>
int ft_strlen(char *str)
{
	int i = -1;
	while(str && str[++i]);
	return i;
}

char *ft_strjoin(int size, char **str, char *sep)
{
    if( str == NULL || size == 0 || sep == NULL)
        return NULL;

	int sep_len= ft_strlen(sep);
	int total_len = 0;
	char *ptr;
	int i = 0;
	int j = 0;
	int k = 0;
	while(i<size)
	{
		total_len += ft_strlen(str[i]);
		if(i < size-1)
			total_len += sep_len;
		i++;
	}
	printf("len = %d\n",total_len);
	ptr = malloc(sizeof(char) * (total_len + 1));
	i = 0;
	while(i < size)
	{
		while( str && str[i][k])
			ptr[j++] = str[i][k++];
		k = 0;
		while(sep[k] && i < size -1)
			ptr[j++] = sep[k++];
		k = 0;
		i++;
	}
	ptr[k+j]= 0;
	return(ptr);
}
int main(int ac,char **av)
{
	char **s ;
	s = av;
	char *str ;
	str = ft_strjoin(3,s+1,"--");
	printf("%s\n",str);
}