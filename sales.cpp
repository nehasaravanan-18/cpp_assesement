#include <stdio.h>
#include <string.h>
#include <vector>
#include <cstring>

using namespace std;




//employee cls
class employee
{
public:
    int employeeid;
    char name[50];
    float salary;

    employee()
    {
        employeeid = 0;
        salary = 0;
        strcpy (name, "");
    }
};





//customer cls
class  customer
{
public:
    int customerid = 0;
    char name[50];
    char address[100];

    customer()
    {
        customerid = 0;
        strcpy(name,"");
        strcpy(address,"");
    }
};





//sale cls....ipo only ids can stored later during deserialize actual references will stored
class sale
{
public:
    int saleid;
    int employeeid;
    int customerid;
    float amount;


    sale()
    {
        saleid = 0;
        employeeid = 0;
        customerid = 0;
        amount = 0;
    }
};








//employeetree node creation
class employeenode
{
public:
    employee data;
    employeenode* left;
    employeenode* right;

    //constr with parameter   emp-new node store employe in its data member
    employeenode(employee emp)  
    {
        data = emp;

        left = NULL;
        right = NULL;

    }
};






//customertree node
class customernode
{
public:
    customer data;
    customernode* left;
    customernode* right;

    customernode(customer cust)  
    
    {
        data = cust;

        left = NULL;
        right = NULL;
    }
};







//saletree node
class salenode
{
public:
    sale data;
    salenode* left;
    salenode* right;

    salenode(sale salee) 
    {
        data = salee;

        left = NULL;
        right = NULL;
    }
};







//emplyee binary search tree
class employeetree
{
private:
    employeenode* root;


    //inserting nodes
    employeenode* insertnode(employeenode* node, employee emp)
    {
        if (node == NULL)
        {
            return new employeenode(emp);
        }
        if (emp.employeeid < node->data.employeeid)
        {
            node->left = insertnode(node->left, emp);
        }
        else
        {
            node->right = insertnode(node->right, emp);
        }

        return node;
    }


    void inorder(employeenode* node)
    {
        if (node == NULL)
            return;

        
        inorder(node->left);
        printf("Employee id : %d\n", node->data.employeeid);
        printf("Name : %s\n", node->data.name);
        printf("Salary : %.2f\n\n", node->data.salary);
        inorder(node->right);   
    }





public:
    employeetree()
    {
        root = NULL;
    }

    void add(employee emp)
    {
        root = insertnode(root, emp);
    }



    void displayall()
    {
        inorder(root);
    }


    employeenode* getroot()
    {
        return root;
    }




    //search employee
    employeenode* search(employeenode* node,int id)
    {
        if (node==NULL)
        {
            return NULL;
        }
        if (node->data.employeeid == id)
        {
            return node;
        }
        if (id < node->data.employeeid)
            return search(node->left, id);
        
        return search(node->right, id);
    }

   
    //check employee exists
    bool exists(int id)
    {
        return search(root, id) != NULL;
    }




    //count emplys...nxt implement of countnodes and serializenodes
    int countnodes(employeenode* node)
    {
        if(node == NULL)
            return 0 ;

        return 1+countnodes(node->left) + countnodes(node->right);
    }

    int getcount()
    {
        return countnodes(root);
    }






    //find employee by name
    employeenode* findbyname(employeenode* node,const char* name)
    {
        if(node == NULL)
            return NULL;

        if (strcmp(node->data.name,name)==0)
        {
            return node;
        }

        employeenode* leftresult = findbyname(node->left,name);

        if (leftresult != NULL)
        
            return leftresult;
        
        return findbyname(node->right,name);
    }


    employeenode* findbyname(const char* name)
    {
        return findbyname(root, name);
    }
};









//customer binary tree
class customertree
{
private:
    customernode* root;

    customernode* insertnode(customernode* node, customer cust)
    {
        if (node == NULL)
        {
            return new customernode(cust); 
        }

        if (cust.customerid<node->data.customerid)
        {
            node->left = insertnode(node->left, cust);
        }
        else
        {
            node->right = insertnode(node->right, cust);
        }

        return node;        
    }


void inorder(customernode* node)
{
    if (node == NULL)
        return;
    
    inorder(node->left);
    printf("Customer id : %d\n", node->data.customerid);
    printf("Name : %s\n", node->data.name);
    printf("Address : %s\n\n", node->data.address);
    inorder(node->right);
}





public:
    customertree()
    {
        root = NULL;
    }


    void add(customer cust)
    {
        root = insertnode(root, cust);
    }


    void displayall()
    {
        inorder(root);
    }


    customernode* getroot()
    {
        return root;
    }




//search customer
customernode* search(customernode* node, int id)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->data.customerid == id)
    {
        return node;
    }
    if (id < node->data.customerid)
        return search(node->left, id);                        
    
    return search(node->right, id); 
}

//exists or not
bool exists(int id)
{
    return search(root, id) != NULL;
}





//count
int countnodes(customernode* node)
{
    if(node == NULL)
        return 0;

    return 1+countnodes(node->left) + (countnodes(node->right));
}

int getcount()
{
    return countnodes(root);
}





//customer search by id
customer* getcustomer(int id)
{
    customernode* node = search(root, id);

    if (node == NULL)
        return NULL;

    return &(node->data);

}
};









//sale binary search tree
class saletree
{
private:
    salenode* root;

    salenode* insertnode(salenode* node, sale salee)
    {
        if (node == NULL)
        {
            return new salenode(salee);
        }

        if (salee.saleid< node->data.saleid)
        {
            node->left = insertnode(node->left, salee);
        }
        else
        {
            node->right = insertnode(node->right, salee);
        }

        return node;
    }


void inorder(salenode* node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    printf("sale id: %d\n", node->data.saleid);
    printf("employee id : %d\n", node->data.employeeid);
    printf("customerid : %d\n", node->data.customerid);
    printf("amount : %.2f\n\n", node->data.amount);
    inorder(node->right);    
}





public:
    saletree()
    {
        root = NULL;
    }

    void add(sale salee)
    {
        root = insertnode(root, salee);
    }

    void displayall()
    {
        inorder(root);
    }


    //sale traversal for reporting
    salenode* getroot()
    {
        return root;
    }





    //search sales
    salenode* search(salenode* node, int id)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (node->data.saleid == id)
        {
            return node;
        }
        if(id < node->data.saleid)
            return search(node->left, id);

        return search(node->right, id);
    }


    bool exists(int id)
    {
        return search(root, id) != NULL;
    }


    


    int countnodes(salenode* node)
    {
        if(node == NULL)
            return 0;

        return 1+ countnodes(node->left) + countnodes(node->right);
    }

    int getcount()
    {
        return countnodes(root);
    }

   
};







//converting all objects into a byte stream
/*
bytes--stores all serialize data
*/
class Serializer
{

public:
    vector<char> bytes;     //acts as a bytes buffer
    //add any objs into byte stream
    void addbytes(void* data, int size)
    {
        char* ptr = (char*)data;

        for (int i = 0; i < size; i++)
        {
            bytes.push_back(ptr[i]);
        }
        
    }
};






//serialize employee tree---inorder traversal
void serializeemployees (employeenode* node,Serializer& serializer)
{
if (node == NULL)

    return;

serializeemployees(node->left, serializer);

serializer.addbytes(&(node->data), sizeof(employee));

serializeemployees(node->right,serializer);
}






//serialize customer tree
void serializecustomers(customernode* node, Serializer& serializer)
{
    if(node==NULL)
        return;

    serializecustomers(node->left,serializer);

    serializer.addbytes(&(node->data), sizeof(customer));

    serializecustomers(node->right, serializer);
}







//sale tree serializer
void serializesales(salenode* node, Serializer& serializer)
{
    if(node == NULL)
        return;

    serializesales(node->left, serializer);

    serializer.addbytes(&(node->data), sizeof(sale));

    serializesales(node->right, serializer);
}







vector<char> serialize (employeetree& employeeTree, customertree& customerTree, saletree& saleTree)
{
    Serializer serializer;

    int employeecount = employeeTree.getcount();
    serializer.addbytes(&employeecount, sizeof(int));
    serializeemployees(employeeTree.getroot(), serializer);

    int customercount = customerTree.getcount();
    serializer.addbytes(&customercount, sizeof(int));
    serializecustomers(customerTree.getroot(), serializer);

    int salecount = saleTree.getcount();
    serializer.addbytes(&salecount, sizeof(int));
    serializesales(saleTree.getroot(),serializer);

    return serializer.bytes;
}






//file handling --- Writing Data.bin , Reading Data.bin
class filehandling
{
public:
    //Save byte stream into Data.bin

    static void writefile(vector<char>& data)
    {
        FILE* fp = fopen("Data.bin","wb");

    if (fp == NULL)
    {
        printf("Can't create file\n");
        return;
    }

    fwrite(data.data(),sizeof(char),data.size(),fp);
    fclose(fp);
    printf("Data saved and serialized\n");
    
    }


    //read data.bin     it returns vector<char>
    static vector<char> readfile()
    {
        vector<char> bytes;

        FILE* fp = fopen("Data.bin", "rb");
        
        if (fp == NULL)
        {
            printf("Data.bin not found\n");
            return bytes;
        }


        //move file to end
        fseek(fp, 0, SEEK_END);

        long filesize = ftell(fp);


        //move back to start
        rewind(fp);

        bytes.resize(filesize);

        fread(bytes.data(),sizeof(char),filesize, fp);
        fclose(fp);
        printf("Data loaded\n");

        return bytes;
        
    }
};







//byte reader---Reads bytes sequentially from vector<char>
class bytereader
{

    vector<char>& bytes;
    int position;

public:
    bytereader(vector<char>& data):bytes(data)
    {
        position = 0;
    }

    void read(void* destination, int size)
    {
        memcpy(destination, &bytes[position],size);
        position += size;
    }
};







//deserialize-Entire Database rebuilds all BSTs
void deserialize(vector<char>& bytes, employeetree& employeeTree,customertree& customerTree, saletree& saleTree)
{
    if (bytes.size() == 0)
    {
        printf("no data to deserialize\n");
        return;
    }

    bytereader reader(bytes);



    //employeescounts
    int employeecount;
    reader.read(&employeecount,sizeof(int));

    for (int i = 0; i < employeecount; i++)
    {
        employee emp;
        reader.read(&emp,sizeof(employee));
        employeeTree.add(emp);
    }



    //customerscounts
    int customercount;
    reader.read(&customercount, sizeof(int));

    for (int i = 0; i < customercount; i++)
    {
        customer cust;
        reader.read(&cust, sizeof(customer));
        customerTree.add(cust);
    }




    //salescounts
    int salecount;
    reader.read(&salecount, sizeof(int));

    for (int i = 0; i < salecount; i++)
    {
        sale salee;
        reader.read(&salee, sizeof(sale));
        saleTree.add(salee);
    }

    printf("deserialization complete\n");
       
}






//customer summmary--->used for grouping sales by customer
class customersummary
{
public:
    int customerid;
    char customername[50];
    int salecount;
    float totalamount;

    customersummary()
    {
        customerid = 0;
        salecount = 0;
        totalamount = 0;

        strcpy(customername, "");
    }
};








/*
Search Employee Report

Displays:

1. Employee Details
2. All Sales
3. Total Sales Count
4. Total Sales Amount
5. Customer Grouping
*/
void processsales(salenode* node, int employeeid, customertree& customerTree,customersummary summary[],int& summarycount, int& totalsales,float& totalamount)
{
    if(node == NULL)
        return;

    processsales(node->left,employeeid,customerTree,summary,summarycount,totalsales,totalamount);


    if (node->data.employeeid == employeeid)
    {
        totalsales++;

        totalamount += node->data.amount;

        printf("sale id : %d\n",node->data.saleid);
        printf("customer id : %d\n", node->data.customerid);
        printf("amount : %.2f\n",node->data.amount);

        printf("\n------------\n");

        bool found = false;

        for (int i = 0; i < summarycount; i++)
        {
            if (summary[i].customerid == node->data.customerid)
            {
                summary[i].salecount++;
                summary[i].totalamount += node->data.amount;
                found = true;
                break;
            }   
        }


        if (!found)
        {
            customer* scustomer = customerTree.getcustomer(node->data.customerid);

            summary[summarycount].customerid = node->data.customerid;
            summary[summarycount].salecount = 1;
            summary[summarycount].totalamount = node->data.amount;

            if (scustomer != NULL)
            {
                strcpy(summary[summarycount].customername,scustomer->name);
            }

            summarycount++;   
        }
    }


    processsales(node->right, employeeid, customerTree,summary,summarycount,totalsales,totalamount);
    
}






//main search function---->search emp by name
void searchEmpreport(employeetree& employeeTree,customertree& customerTree,saletree& saleTree)
{
    char employename[50];

    printf("\nenter emp name: ");
    scanf("%s", employename);

    employeenode* employee = employeeTree.findbyname(employename);


    if (employee == NULL)
    {
        printf("\nemp not found\n");
        return;
    }


    printf("\n===Employee details====\n");

    printf("id = %d\n", employee->data.employeeid);
    printf("name : %s\n",employee->data.name);
    printf("salary: %.2f\n",employee->data.salary);

    int totalsales = 0;

    float totalamount = 0;

    customersummary summary [100];

    int summarycount = 0;

    printf("\n===sales details===\n");

    processsales(saleTree.getroot(),employee->data.employeeid,customerTree,summary,summarycount,totalsales,totalamount);
    
    printf("\n===summary===\n");
    printf("No of sales : %d\n",totalsales);
    printf("Total amount : %.2f\n", totalamount);


    printf("\n===customer wise summary===");

    for (int i = 0; i < summarycount; i++)
    {
        printf("customer id : %d\n",summary[i].customerid);
        printf("customer name : %s\n",summary[i].customername);
        printf("sales count : %d\n", summary[i].salecount);
        printf("total amount: %.2f\n\n",summary[i].totalamount);
    }
}







//add functions
//add employee
    void addemployee(employeetree& employeeTree)
    {
        employee emp;

        printf ("\nenter emp id : ");
        scanf("%d" , &emp.employeeid);

        if (employeeTree.exists(emp.employeeid))
        {
            printf("employee id exists\n");
            return;
        }

        printf("enter emp name : ");
        scanf("%s", emp.name);

        printf("enter emp salary : ");
        scanf("%f", &emp.salary);

        employeeTree.add(emp);

        printf("\nemp added\n\n");   
    }





//add customer
void addcustomer(customertree&customerTree)
{
    customer cust;

    printf("\nenter cust id : ");
    scanf("%d", &cust.customerid);

    if (customerTree.exists(cust.customerid))
    {
        printf("customer id exixts");
        return;
    }

    printf("enter cust name : ");
    scanf("%s", cust.name);

    printf("enter ur address : ");
    scanf("%s", cust.address);
    
    customerTree.add(cust);
    
    printf("\ncustomer added\n\n");
}






//add sales
// validates  1.sale id    2.emp id     3.cust id
void addsale(saletree&saleTree, employeetree&employeeTree, customertree& customerTree)
{
    sale salee;

    printf("\nenter sale id : ");
    scanf("%d", &salee.saleid);

    if (saleTree.exists(salee.saleid))
    {
        printf("sale id exists");
        return;
    }

    printf("enter emp id : ");
    scanf("%d", &salee.employeeid);

    if (!employeeTree.exists(salee.employeeid))
    {
        printf("employe not found\n");
        return;
    }

    printf("enter cust id : ");
    scanf("%d", &salee.customerid);

    if (!customerTree.exists(salee.customerid))
    {
        printf("cust not found\n");
        return;
    }

    printf("enter sale amount : ");
    scanf("%f", &salee.amount);

    saleTree.add(salee);

    printf("sale added");

}





    


    
/*

serialize objects   -   serialize()
write serialized data to data.bin - writefile()
read data.bin       -   loadfile()
deserialize objects -   deserialze()


1
insert sample records
verify binary trees work correctly

2
employe bst, cust bst, sale bst
add emp,cust,sale
search emp,cust
duplicate id check
emp validation in sales , cust vali in sales
menu 

3
(Counting the number of nodes.
Writing the count into Data.bin.
Traversing the BST in inorder.
Writing each object's data using fwrite().)

vector<char> serialization buffer
Serialize Employees
Serialize Customers
Serialize Sales
Single byte stream output
vector<char> Return	
Binary Tree Traversal	
Store Counts
destructors pending.....


Serialization creates:

EmployeeCount
Employee Bytes
CustomerCount
Customer Bytes
SaleCount
Sale Bytes--------->it all stored inside vector<char>
 


4
Write Serialized data to file called Data.bin
Load file called Data.bin if present
Use binary file and not text file
writeFile()
loadFile()
Binary file creation
Binary file reading
Use fwrite()
Use fread()



5
Data.bin → Read
Bytes → Objects
Rebuild Employee BST
Rebuild Customer BST
Rebuild Sale BST
deserialize


6
Search Employee By Name
Show All Sales
Total Sales Count
Total Sales Amount
Group By Customer
Customer Sales Count
Customer Total Amount
*/



int main ()
{
    employeetree employeeTree;
    customertree customerTree;
    saletree saleTree;


    int choice;

    while ((true))
    {

        printf("================");
        printf("\n1.add emp \n2.add cust \n3.add sale \n4.show emp's \n5.show cust's \n6.show sale's \n7.searchEmpReport \n8.serialize and save \n9.Load & deserialize file \n10.exit\n");
        printf("================");


        printf("\nenter choice : ");
        scanf("%d", &choice);
        printf ("\n");

        switch (choice)
        {
        case 1:
            addemployee(employeeTree);
            break;
        
        case 2:
            addcustomer(customerTree);
            break;
        
        case 3:
            //cant store emp id or cant display
            addsale(saleTree,employeeTree,customerTree);
            break;

        case 4:
            employeeTree.displayall();
            break;

        case 5:
            customerTree.displayall();
            break;

        case 6:
            saleTree.displayall();
            break;

        case 7:
            searchEmpreport(employeeTree,customerTree,saleTree);
            break;

        case 8:
        {
            vector<char> data = serialize(employeeTree,customerTree,saleTree);
            filehandling::writefile(data);

            break;
        }

        case 9:
        {
            vector<char> data = filehandling::readfile();
            deserialize(data, employeeTree,customerTree,saleTree);
            break;
        }

        case 10:
            printf("\nprogram exits\n");
            return 0;


        default:
            printf("\ninvalid choice\n");
        }
    }
}
