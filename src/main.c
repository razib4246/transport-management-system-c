#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[100];
    char id[50];
    char address[100];
    char destination_route[100];
    char assign_bus[50];
    struct student *next;
} Student;

typedef struct bus
{
    char bus_name[50];
    char route_name[100];
    char time_from_dsc[20];
    char time_from_route[20];
    char driver_name[100];
    struct bus *next;
} Bus;

Student *student_head = NULL;
Bus *bus_head = NULL;
Student *student_profile=NULL;


void print_heading();
void main_menu();
void admin_login();
void manage_student();
void add_student();
void save_student_info();
void load_student_info();
Student *find_student_by_id(char *id);
void remove_student();
void update_student_info();
void student_list();
void manage_bus();
void add_bus();
void save_bus_info();
void load_bus_info();
Bus *find_bus_by_name(char *name);
void remove_bus();
void update_bus_info();
void bus_list();
Bus *find_bus_by_route(char *route);
void student_login();
void save_notice(char *date,char *main_body);
void load_notice();
void About();

int main()
{

    load_student_info();
    load_bus_info();
    load_notice();

    main_menu();
}
void print_heading(char *text)
{
    int length=strlen(text);
    for(int i=0; i<length; i++)
    {
        printf("_");
    }
    printf("\n");
    printf("%s",text);
    printf("\n");
    for(int i=0; i<length; i++)
    {
        printf("-");
    }
    printf("\n\n\n");

}
void main_menu()
{
    system("cls");
    printf("\n");
    print_heading("| MAIN MENU |");
    printf("1.Admin Login\n2.Student Login\n3.Helpline\n4.About Developer\n0.Exit\n\n");
    int option;
    printf("Enter a option : ");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
    {
        system("cls");

        char pass[10];
        printf("Enter password to login : ");
        scanf(" %[^\n]s",pass);
        if(strcmp(pass,"12345")==0)
        {

            admin_login();
        }
        else
        {
            printf("Incorrect password\n");
            system("pause");
            main_menu();
        }
    }
    break;
    case 2:
    {

        system("cls");

        char pass[10],id[20];
        printf("Enter your ID to login : ");
        scanf(" %[^\n]s",id);
        Student *s=find_student_by_id(id);
        student_profile=s;
        if(s==NULL)
        {
            printf("You are not registered for Transport Service!!\n");
            system("pause");
            return main_menu();
        }
        printf("Enter password : ");
        scanf(" %[^\n]s",pass);
        if(strcmp(pass,"12345")==0)
        {


            student_login();

        }
        else
        {
            printf("Incorrect password\n");
            system("pause");
            main_menu();
        }
    }
    break;
    case 3:
    {
        system("cls");
        print_heading("| HELPLINE |");
        printf("\"DAFFODIL INTERNATIONAL UNIVERSITY\"\n\n");
        printf("Address:Daffodil Smart City(DSC),Birulia,Savar,Dhaka-1216\n");
        printf("Telephone No: 09617901212,09617901233\n");
        printf("Web: www.daffodilvarsity.edu.bd\n\n");
        system("pause");
        return main_menu();
    }
    break;
    case 4:
            About();
            break;
    case 0:
        exit(0);
    default :
        system("cls");
        printf("Incorrect Option!!\n");
        system("pause");
        return main_menu();

    }
}
void admin_login()
{
    system("cls");
    print_heading("| ADMIN LOGIN |");

    printf("1.Manage Student\n2.Manage Bus\n3.Main Menu\n\n");
    int option;
    printf("Enter a option : ");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        manage_student();
        break;
    case 2:
        manage_bus();
        break;
    case 3:
        main_menu();
        break;
    default:
        printf("Incorrect option!!\n");
        system("pause");
        return admin_login();
    }

}
void manage_student()
{
    system("cls");
    print_heading("| STUDENT MANAGEMENT |");
    printf("1.Add Student\n2.Remove Student\n3.Update Student Information\n");
    printf("4.Find a Student by ID\n5.Student List\n6.Announcement\n7.Back\n8.Main Menu\n\n");
    int option;
    printf("Enter a option : ");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
    {
        add_student();

        system("pause");
        return manage_student();
    }
    break;
    case 2:
        remove_student();
        system("pause");
        return manage_student();
        break;
    case 3:

        update_student_info();
        break;
    case 4:
    {
        system("cls");
        print_heading("| STUDENT SEARCH |");
        printf("Enter Student ID to Find : ");
        char id[50];

        scanf(" %[^\n]s",id);
        Student *s=student_head;
        s=find_student_by_id(id);


        if(s==NULL)
        {
            printf("Student Not found.\n");
            system("pause");
            return manage_student();
        }
        printf("Student is found.Details info--\n\n");
        printf("Student's Name: %s\nStudent's ID: %s\nAddress: %s\n",s->name, s->id, s->address);
        printf("Destination: %s\nAssigned Bus: %s\n",s->destination_route,s->assign_bus);
        system("cls");
        system("pause");
        return manage_student();

    }
    break;
    case 5:
        student_list();
        system("pause");
        manage_student();
        break;
    case 6:
    {
        system("cls");
        print_heading("| ANNOUNCEMENT |");
        char date[20],main_body[500];
        printf("Create an announcement:\n\n");
        printf("Date : ");
        scanf(" %[^\n]s",date);
        printf("Write the full announcement below:\n");
        scanf(" %[^\n]s",main_body);
        save_notice(date,main_body);
        printf("\nThe announcement is written successful.\n\n");
        printf("Here is the announcement : \n");
        load_notice();
        system("pause");
        return manage_student();
    }
    break;
    case 7:
        admin_login();
        break;
    case 8:
        main_menu();

        break;
    default:
        printf("INCORRECT OPTION!!\n\n");

    }
}
void add_student()
{
    system("cls");
    print_heading("| ADD STUDENT |");
    Student *node = malloc(sizeof(Student));

    printf("Student's Name: ");
    scanf(" %[^\n]s", node->name);

    printf("Student ID(like XXX-XX-XX): ");
    scanf(" %[^\n]s", node->id);
    Student *temp=student_head;
    if(find_student_by_id(node->id)!=NULL)
    {
        printf("The Student is already existed!!\n");
        free(node);
        system("pause");
        return manage_student();
    }
    printf("Address: ");
    scanf(" %[^\n]s", node->address);

    printf("Destination: ");
    scanf(" %[^\n]s", node->destination_route);


    printf("Assigned Bus Name: ");
    scanf(" %[^\n]s",node->assign_bus);
    Bus *assigned_bus = find_bus_by_name(node->assign_bus);
    Bus *route=find_bus_by_route(node->destination_route);
    if(assigned_bus == NULL || route== NULL)
    {
        printf("There is no assigned bus for this route!\n");
        free(node);
        system("pause");
        return manage_student();
    }
    node->next = NULL;


    if(student_head==NULL)
    {
        student_head=node;
    }
    else
    {
        temp=student_head;
        while(temp->next!=NULL)
        {
            temp=temp->next;

        }
        temp->next=node;
    }

    save_student_info();
    printf("Student added.\n");

}

void save_student_info()
{
    FILE *fp=NULL;
    fp=fopen("StudentInfo.txt","w");
    if(fp==NULL)
    {
        return ;
    }
    else
    {
        Student *p=student_head;
        while(p!=NULL)
        {
            fprintf(fp,"|%s| |%s| |%s| |%s| |%s|\n",p->name,p->id,p->address,p->destination_route,p->assign_bus);
            p=p->next;
        }
    }
    fclose(fp);
}
Student *find_student_by_id(char *id)
{
    Student *temp=student_head;
    while(temp!=NULL)
    {
        if(strcmp(temp->id,id)==0)
        {
            return temp;
        }

        temp=temp->next;
    }
    return NULL;
}
void remove_student()
{
    system("cls");
    print_heading("| REMOVE STUDENT |");
    char id[50];
    printf("Enter student ID to remove : ");
    scanf("%s",id);
    Student *s=find_student_by_id(id);
    if(s==NULL)
    {
        printf("Student not found!\n");
        return ;
    }
    else
    {
        if(s==student_head)
        {
            student_head=s->next;
            free(s);
        }
        else
        {
            Student *p=student_head;
            while(p->next!=s)
            {
                p=p->next;
            }
            p->next=s->next;
        }
    }

    save_student_info();
    printf("Student deletion is successful\n\n");
}
void load_student_info()
{
    FILE *fp = fopen("StudentInfo.txt", "r");
    if(fp==NULL)
    {
        return ;
    }

    Student *node = NULL;
    while(1)
    {
        node = malloc(sizeof(Student));
        if(fscanf(fp, "|%[^|]| |%[^|]| |%[^|]| |%[^|]| |%[^|]|\n",
                  node->name, node->id, node->address, node->destination_route, node->assign_bus) != 5)
        {
            free(node);
            break;
        }

        node->next = NULL;
        if(student_head == NULL)
        {

            student_head = node;
        }
        else
        {
            Student *p = student_head;
            while(p->next!=NULL)
            {
                p = p->next;
            }
            p->next = node;
        }
    }
    fclose(fp);
}
void update_student_info()
{
    system("cls");
    print_heading("| UPDATE STUDENT INFORMATION |");
    printf("Enter Student's ID : ");
    char id[50];

    scanf(" %[^\n]s",id);
    Student *p=find_student_by_id(id);
    if(p==NULL)
    {
        printf("No Student found!\n");
        system("pause");
        return manage_student();
    }
    else
    {
        printf("Provide Update Information :\n\n");
        printf("Student's Name: ");
        scanf(" %[^\n]s", p->name);

        printf("Student ID(like XXX-XX-XX): ");
        scanf(" %[^\n]s", p->id);

        printf("Address: ");
        scanf(" %[^\n]s", p->address);

        printf("Destination: ");
        scanf(" %[^\n]s", p->destination_route);

        getchar();
        printf("Assign Bus: ");
        scanf("%[^\n]s",p->assign_bus);
        Bus *assigned_bus = find_bus_by_name(p->assign_bus);
        if(assigned_bus == NULL || strcmp(assigned_bus->route_name, p->destination_route) != 0)
        {
            printf("There is no assigned bus for this route!\n");
            free(p);
            system("pause");
            return manage_student();
        }

        save_student_info();
        student_head=NULL;
        load_student_info();
        printf("Student Information update Successful\n");
        system("pause");
        return manage_student();
    }
}
void student_list()
{
    system("cls");
    Student *p=student_head;
    if(p==NULL)
    {
        printf("No Student found!!\n");
        system("pause");
        return manage_student();
    }
    else
    {
        printf("Registered students list:\n\n");
        int i=1;
        printf("%-4s %-22s %-22s %-22s %-22s %s\n\n","NO","Name","ID","ADDRESS","DESTINATION","ASSIGNED BUS");
        while(p!=NULL)
        {
            printf("%d.| %-20s | %-20s | %-20s | %-20s | %-15s |\n",i,
                   p->name,p->id,p->address,p->destination_route,p->assign_bus);
            i++;
            p=p->next;
        }
        printf("\n\nTotal Registered Student number: %d\n",i-1);
        system("pause");
        return manage_student();
    }
}

void manage_bus()
{
    system("cls");
    print_heading("| BUS MANAGEMENT |");
    printf("1.Add Bus\n2.Remove Bus\n3.Update Bus Information\n4.Find Bus by name\n5.Find Bus By Route\n6.Bus List\n7.Back\n8.Main Menu\n\n");
    int option;
    printf("Enter a option : ");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        add_bus();
        system("pause");
        return manage_bus();
        break;
    case 2:
        remove_bus();
        system("pause");
        return manage_bus();
        break;
    case 3:
        getchar();
        update_bus_info();
        break;
    case 4:
    {
        system("cls");
        print_heading("| BUS SEARCH |");
        printf("Enter Bus Name to Find : ");
        char name[50];
        getchar();
        scanf("%[^\n]s",name);
        Bus *b=find_bus_by_name(name);

        if(b==NULL)
        {
            printf("Bus Not found.\n");
            system("pause");
            return manage_bus();
        }
        printf("Bus is found. Details info--\n\n");
        printf("Bus Name: %s\nRoute: %s\nDeparture Time from DSC: %s\nDeparture Time from Route: %s\nDriver: %s\n",
               b->bus_name, b->route_name, b->time_from_dsc, b->time_from_route, b->driver_name);
        system("pause");
        return manage_bus();
    }
    break;
    case 5:
    {
        system("cls");
        print_heading("| SEARCH BUS BY ROUTE |");
        printf("Enter Route Name to Find : ");
        char route[100];
        getchar();
        scanf("%[^\n]s",route);
        Bus *b=find_bus_by_route(route);

        if(b==NULL)
        {
            printf("Bus Not found for this route.\n");
            system("pause");
            return manage_bus();
        }
        printf("Bus is found. Details info--\n\n");
        printf("Bus Name: %s\nRoute: %s\nDeparture Time from DSC: %s\nDeparture Time from Route: %s\nDriver: %s\n",
               b->bus_name, b->route_name, b->time_from_dsc, b->time_from_route, b->driver_name);
        system("pause");
        return manage_bus();
    }
    break;
    case 6:
        bus_list();
        system("pause");
        return manage_bus();
        break;
    case 7:
        admin_login();
        break;
    case 8:
        main_menu();
        break;
    default:
        printf("INCORRECT OPTION!!\n\n");
    }
}

void add_bus()
{
    system("cls");
    print_heading("| ADD BUS |");
    Bus *node = malloc(sizeof(Bus));

    printf("Bus Name: ");
    scanf(" %[^\n]s", node->bus_name);

    printf("Route Name: ");
    scanf(" %[^\n]s", node->route_name);

    Bus *temp = bus_head;
    while(temp != NULL)
    {
        if(strcmp(temp->bus_name, node->bus_name) == 0 &&
                strcmp(temp->route_name, node->route_name) == 0)
        {
            printf("This Bus already exists!!\n");
            free(node);
            system("pause");
            return manage_bus();
        }
        temp = temp->next;
    }

    printf("Departure Time from DSC: ");
    scanf(" %[^\n]s", node->time_from_dsc);

    printf("Departure Time from Route: ");
    scanf(" %[^\n]s", node->time_from_route);

    printf("Driver Name: ");
    scanf(" %[^\n]s", node->driver_name);

    node->next = NULL;

    if(bus_head==NULL)
    {
        bus_head=node;
    }
    else
    {
        Bus *temp=bus_head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=node;
    }

    save_bus_info();
    printf("Bus added successfully.\n");
}

void save_bus_info()
{
    FILE *fp=fopen("BusInfo.txt","w");
    if(fp==NULL)
    {
        return;
    }

    Bus *p=bus_head;
    while(p!=NULL)
    {
        fprintf(fp,"|%s| |%s| |%s| |%s| |%s|\n",
                p->bus_name, p->route_name, p->time_from_dsc, p->time_from_route, p->driver_name);

        p=p->next;
    }
    fclose(fp);
}

void load_bus_info()
{
    FILE *fp = fopen("BusInfo.txt", "r");
    if(fp==NULL)
    {
        return;
    }

    Bus *node = NULL;
    while(1)
    {
        node = malloc(sizeof(Bus));
        if(fscanf(fp, "|%[^|]| |%[^|]| |%[^|]| |%[^|]| |%[^|]|\n",
                  node->bus_name, node->route_name, node->time_from_dsc, node->time_from_route, node->driver_name) != 5)
        {
            free(node);
            break;
        }

        node->next = NULL;
        if(bus_head == NULL)
        {
            bus_head = node;
        }
        else
        {
            Bus *p = bus_head;
            while(p->next!=NULL)
            {
                p = p->next;
            }
            p->next = node;
        }
    }
    fclose(fp);
}

Bus *find_bus_by_name(char *name)
{
    Bus *temp=bus_head;
    while(temp!=NULL)
    {
        if(strcmp(temp->bus_name,name)==0)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

Bus *find_bus_by_route(char *route)
{
    Bus *temp=bus_head;
    while(temp!=NULL)
    {
        if(strcmp(temp->route_name,route)==0)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

void remove_bus()
{
    system("cls");
    print_heading("| REMOVE BUS |");
    char name[50];
    printf("Enter Bus Name to remove : ");
    getchar();
    scanf("%[^\n]s",name);

    Bus *b=find_bus_by_name(name);
    if(b==NULL)
    {
        printf("Bus not found!\n");
        return;
    }
    else
    {
        if(b==bus_head)
        {
            bus_head=b->next;
        }
        else
        {
            Bus *p=bus_head;
            while(p->next!=b)
            {
                p=p->next;
            }
            p->next=b->next;
        }
    }
    free(b);
    save_bus_info();
    printf("Bus removed successfully.\n");
}

void update_bus_info()
{
    system("cls");
    print_heading("| UPDATE BUS INFORMATION |");
    printf("Enter Bus Name : ");
    char name[50];

    scanf(" %[^\n]s",name);
    Bus *p=find_bus_by_name(name);
    if(p==NULL)
    {
        printf("No Bus found!\n");
        system("pause");
        return manage_bus();
    }
    else
    {
        printf("Provide Update Information :\n\n");

        printf("Bus Name: ");
        scanf(" %[^\n]s", p->bus_name);

        printf("Route Name: ");
        scanf(" %[^\n]s", p->route_name);

        printf("Departure Time from DSC: ");
        scanf(" %[^\n]s", p->time_from_dsc);

        printf("Departure Time from Route: ");
        scanf(" %[^\n]s", p->time_from_route);

        printf("Driver Name: ");
        scanf(" %[^\n]s", p->driver_name);

        save_bus_info();
        bus_head=NULL;
        load_bus_info();
        printf("Bus Information updated successfully.\n");
        system("pause");
        return manage_bus();
    }
}

void bus_list()
{
    system("cls");
    print_heading("| BUS LIST |");
    Bus *p=bus_head;

    if(p==NULL)
    {
        printf("No Bus found!!\n");
        system("pause");
        return manage_bus();
    }
    else
    {
        printf("Available Buses:\n\n");
        int i=1;
        printf("%-4s %-15s %-18s %s %-12s %s\n\n","No","Bus Name","Route Name","Time(DSC)","Time(Route)","Driver Name");
        while(p!=NULL)
        {
            printf("%d.| %-15s | %-15s | %-8s | %-8s | %-20s |\n",i,
                   p->bus_name, p->route_name, p->time_from_dsc, p->time_from_route, p->driver_name);
            i++;
            p=p->next;
        }
        printf("\n\nTotal Buses: %d\n",i-1);
        system("pause");
        return manage_bus();
    }
}
void student_login()
{
    system("cls");
    print_heading("| STUDENT LOGIN |");
    printf("1.View profile\n2.Find bus by name\n3.Find bus by route\n4.Bus Shedule\n5.View Notice\n6.Back\n");
    printf("\nEnter a option : ");
    int option;
    scanf("%d",&option);
    switch(option)
    {
    case 1:
    {

        system("cls");
        print_heading("| VIEW PROFILE |");

        printf("Details info--\n\n");
        printf("Student's Name: %s\nStudent's ID: %s\nAddress: %s\n",student_profile->name, student_profile->id, student_profile->address);
        printf("Destination: %s\nAssigned Bus: %s\n",student_profile->destination_route,student_profile->assign_bus);

        system("pause");
        return student_login();

    }
    break;
    case 2:
    {

        system("cls");
        print_heading("| SEARCH BUS |");
        char bus_name[50];
        printf("Enter the bus name: ");
        scanf(" %[^\n]s",bus_name);
        Bus *b=find_bus_by_name(bus_name);
        if(b==NULL)
        {
            printf("No bus found with this name!!\n");
            system("pause");
            return student_login();
        }
        printf("Details info about this bus--\n\n");
        printf("Bus Name: %s\nRoute: %s\nDeparture Time from DSC: %s\nDeparture Time from Route: %s\n",
               b->bus_name, b->route_name, b->time_from_dsc, b->time_from_route);
        system("pause");
        return student_login();

    }
    break;
    case 3:
    {
        system("cls");
        print_heading("| SEARCH BUS |");
        char route_name[50];
        printf("Enter the route name: ");
        scanf(" %[^\n]s",route_name);
        Bus *b=find_bus_by_route(route_name);
        if(b==NULL)
        {
            printf("There is no bus assigned for this route!!\n");
            system("pause");
            return student_login();
        }
        printf("Details info about this bus--\n\n");
        printf("Bus Name: %s\nRoute: %s\nDeparture Time from DSC: %s\nDeparture Time from Route: %s\n",
               b->bus_name, b->route_name, b->time_from_dsc, b->time_from_route);
        system("pause");
        return student_login();
    }
    break;
    case 4:
    {
        system("cls");
        print_heading("| BUS SHEDULE |");
        Bus *p=bus_head;

        if(p==NULL)
        {
            printf("No Bus found!!\n");
            system("pause");
            return student_login();
        }
        else
        {
            printf("Available Buses:\n\n");
            int i=0;
            while(p!=NULL)
            {
                printf("| Bus:%s | Route:%s | DSC Time:%s | Route Time:%s |\n",
                       p->bus_name, p->route_name, p->time_from_dsc, p->time_from_route);
                i++;
                p=p->next;
            }
            system("pause");
            return student_login();
        }
    }
    break;
    case 5:
        system("cls");
        print_heading("| NOTIFICATION |");
        load_notice();
        system("pause");
        return student_login();
    case 6:
    {
        system("cls");
        main_menu();
    }
    break;
    default:
        system("cls");
        printf("Invalid option!!\n\n");
        return student_login();


    }
}
void save_notice( char *date,char *main_body)
{

    FILE *fp=fopen("Notice.txt","w");
    if(fp==NULL)
    {
        printf("Notice saving ERROR!!\n");
        return;
    }
    else
    {
        fprintf(fp,"Date : %s \nNotice: %s\n",date,main_body);
        fclose(fp);
    }
}
void load_notice()
{
    FILE *fp=fopen("Notice.txt","r");
    if(fp==NULL)
    {
        printf("No Notice available..!!\n");
        return;
    }
    else
    {
        char line[600];


        while(fgets(line,sizeof(line),fp)!=NULL)
        {
            printf("%s",line);

        }
        printf("\n");


        fclose(fp);
    }
}
void About()
{
    system("cls");
    printf("Made by :\n");
    printf("Md.Osman Gony\n");
    printf("(ID: 251-15-736)\n");
    printf("Pranto Kumar Biswas\n");
    printf("(ID: 251-15-757)\n");
    printf("Md Sabbir Hossen \n");
    printf("(ID: 251-15-395)\n");
    printf("Abu Obaidah Nokib\n");
    printf("(ID: 251-15-045)\n");
    printf("Razib Miah\n");
    printf("(ID: 251-15-617)\n");
    system("pause");
    return main_menu();
}
