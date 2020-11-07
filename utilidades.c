#include "utilidades.h"

/*********************************************************************//**
*
* \brief valida que tenga un "@" el email del cliente
* \param recibe el email
* \return es void
*
**************************************************************************/
int validaEmail(char email[])
{
    int v=strlen(email);
    int i=0;
    int flag=0;
    while(i<v && flag == 0)
    {
        if(email[i]==64)/// =='@'
        {
            flag=1;
        }
        i++;
    }
    return flag;
}

///\brief mostrar un arreglo, recibe el arreglo y sus validos
void mostrarArray(int a[],int v){

  for(int i=0;i<v;i++){
    printf("\n%d\n",a[i]);
  }

}



