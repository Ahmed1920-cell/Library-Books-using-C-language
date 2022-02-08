    #include <stdio.h>
    #include<string.h>
    using namespace std;


    struct libarary{

    int id , quant;
    char book[100];
    };

    FILE *filePointer ;
    void sizez(struct libarary books[],int &sizes){
       if((filePointer = fopen("books.txt", "r+"))==NULL)
        printf("the file can't be opened");
    for(int i=0;i<=sizes;i++){
            fscanf(filePointer,"%d%d",&books[i].id,&books[i].quant);
            fgets(books[i].book,100,filePointer);
                if(strlen(books[i].book)>0){
                sizes++;}}
                fclose(filePointer);

    }

    void inserts(struct libarary books[],int &sizes){
        int lengh , i,start;
        printf("add the book : ");
        scanf("%d",&lengh);
        filePointer = fopen("books.txt", "a") ;
        sizes=sizes+lengh;
        start=sizes-lengh;
        for(i=start;i<sizes;i++){
            getchar();
            printf("enter the name : ");
            gets(books[i].book);
            printf("enter the id : ");
            scanf("%d",&books[i].id);
            printf("enter the quantity : ");
            scanf("%d",&books[i].quant);
        }
        for(i=start;i<sizes;i++){
            //fputs("\n",filePointer);
            fprintf(filePointer,"%d %d %s\n",books[i].id,books[i].quant,books[i].book);
        }
            fclose(filePointer);
    }

    void reading(struct libarary books[],int sizes){

        filePointer = fopen("books.txt", "r");
        if(filePointer==NULL)
        printf("the file is close");
        else
        for(int i=0;i<sizes;i++){
            fscanf(filePointer,"%d%d",&books[i].id,&books[i].quant);
            fgets(books[i].book,100,filePointer);
        }
        fclose(filePointer);
    }
    void printing(struct libarary books[],int sizes){
        printf("%-15s%-13s%s\n ","id","quantity","name");
        for(int i=0 ; i<sizes ; i++){
            printf("\n%-17d%-9d%s\n" , books[i].id,books[i].quant,books[i].book);
        }
        printf("\n");
    }

    void deletes(struct libarary books[],int sizes){
        reading(books,sizes);
        printing(books,sizes);
        int key,i ,temp;
        char *g[100];
        filePointer = fopen("books.txt", "w");
        printf("\nenter the id: ");
        scanf("%d",&key);
        for(i=0;i<sizes;i++){
            if(books[i].id!=key){
                    printf("\n%-17d%-9d%s\n",books[i].id,books[i].quant,books[i].book);
                    fprintf(filePointer,"%d %d%s",books[i].id,books[i].quant,books[i].book);

            }
        }
        fclose(filePointer);
    }
    unsigned int linear(struct libarary books[],int sizes,int key){
        int c=0;
        reading(books,sizes);
        if(sizes>=1){
            if(books[sizes-1].id==key){
            printf("%-15s%-13s%s\n ","id","quantity","name");
            printf("\n%-17d%-7d%s\n",books[sizes-1].id,books[sizes-1].quant,books[sizes-1].book);
            c++;
            fclose(filePointer);}
            else
            return linear(books,sizes-1,key);}
            //else if(sizes=1){
            if(c==0){
            printf("\nthe id not exist\n");
            return 1;}
        }
    void sorted (struct libarary books[],int sizes){
    reading(books,sizes);
    //printing(books,sizes);
    int i,j,temp,temps;
    char g[100];
    int c=2;
    for(i=1;i<c;i++){
        for(j=0;j<sizes-1;j++){
            if(strcmp(books[j].book,books[j+1].book)>0){
                temp=books[j].id;
                books[j].id=books[j+1].id;
                books[j+1].id=temp;
                temps=books[j].quant;
                books[j].quant=books[j+1].quant;
                books[j+1].quant=temps;
                strcpy(g,books[j].book);
                strcpy(books[j].book,books[j+1].book);
                strcpy(books[j+1].book,g);
                c++;

            }
        }
    }
    printf("%-15s%-13s%s\n ","id","quantity","name");
    for(j=0;j<sizes;j++){
            printf("\n%-17d%-9d%s\n" , books[j].id,books[j].quant,books[j].book);

    }
    fclose(filePointer);
    }
    void binarysearch(struct libarary books[],int sizes){
        reading(books,sizes);
        sorted(books,sizes);
        int i,low,high,med;
        char g[100], book[100];
        getchar();
        printf("Enter the name search it: ");
        gets(g);
        low=0;
        high=sizes-1;

        while(low<=high)
        {
            int counter = 0;

            med=(low+high)/2;
            for(int j =0 ; j<strlen(g) ;j++){
                if(g[j] == books[med].book[j+1])
                    counter++;
            }
            for(int j =0 ; j<strlen( books[med].book) ;j++){
                book[j]=books[med].book[j+1];
            }
            if(counter == strlen(g)){
                    printf("%-15s%-13s%s\n ","id","quantity","name");
                printf("\n%-17d%-9d%s\n" , books[med].id,books[med].quant,books[med].book);
                return;
            }
            else if(strcmp(g,book)<0){
                    low = low;
                    high=med-1;
                    }
            else{
                high = high;
                low=med+1;
            }


        }
        printf("the book is not found\n");
        fclose(filePointer);
    }
    int other_operation(){
    int n;
    printf("1:yes\n");
    printf("2:no\n");
    scanf("%d",&n);
    if(n==1)
        return 1;
    else if (n==2)
        return 0;
    }
    int main()
    {
        const int sizes=100;
        struct libarary books[sizes];
        char ch;
        int result;
        int j=0;
        sizez(books,j);
    do{
            printf("the book is enter :%d\n\n",j);
        const int sizes=100;
        int key,c;
        struct libarary books[sizes];
        printf("choose the operation:\n");
        printf(" 1: insert\n");
        printf(" 2: delete\n");
        printf(" 3: linear_search (search by id) \n");
        printf(" 4: print books of unsorted\n");
        printf(" 5: print books of sorted\n");
        printf(" 6: binary_search (search by name) \n");
        scanf("%d",&c);
        // printf("press");
        if(c==1){
        inserts(books,j);
        }
        if(c==2){
        deletes(books,j);
        j--;}
        reading(books,j);
        if(c==3){
        printf("enter the id: ");
        scanf("%d",&key);
    linear(books,j,key);}
    if(c==4)
      printing(books,j);
    if(c==5)
    sorted(books,j);
    // create(books);
    if(c==6)
    {
    printf("how many books are you enter: ");//add 3 books
    scanf("%d",&j);
    binarysearch(books,j);}
    printf("\nwant to another operation\n");
    result= other_operation();
    //scanf(" %c",&ch);
    }
    while(result==1);
    return 0;
}
