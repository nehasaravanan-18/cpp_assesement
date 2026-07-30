#include <stdio.h>
#include <string.h>
#include <iostream>   
using namespace std;                              

class Employee
{
public:
    int employeeId;
    char name[50];
    float salary;

    Employee()
    {
        employeeId = 0;
        salary = 0;
        strcpy(name, " ");
    }
};


class Customer
{
public:
    int customerId;
    char name[50];
    char address[100];

    Customer()
    { 
        customerId = 0;
        strcpy(name, "");
        strcpy(address, "");
    }
};                          
                                                     

class Sale
{
public:
    int saleId;
    int employeeId;
    int customerId;
    float amount;
    
    Sale()
    {
        saleId = 0;
        employeeId = 0;
        customerId = 0;
        amount = 0;
    }
};


class EmployeeNode
{
public:
    Employee* data;
    EmployeeNode* left;
    EmployeeNode* right;

    EmployeeNode(Employee*emp)
    {
        data = emp;
        left = NULL;
        right = NULL;
    }
};


class CustomerNode
{
public:
    Customer* data;
    CustomerNode* left;
    CustomerNode* right;

    CustomerNode(Customer*cust)
    {
        data = cust;
        left = NULL;
        right = NULL;
    }
};


class SaleNode
{
public:
    Sale* data;
    SaleNode* left;
    SaleNode* right;

    SaleNode(Sale*sale)
    {
        data = sale;
        left = NULL;
        right = NULL;
    }
};


class EmployeeTree
{
private:
    EmployeeNode* root;

    EmployeeNode* insert(EmployeeNode* node, Employee* emp)
    {                              
        if(node == NULL)
            return new EmployeeNode(emp);
        if(emp->employeeId < node->data->employeeId)
            node->left = insert(node->left, emp);
        else if(emp->employeeId > node->data->employeeId)
            node->right = insert(node->right, emp);
        return node;
    }

    void inorder(EmployeeNode* node)
    {
        if(node == NULL)
            return;

        inorder(node->left);
        cout<<"\nEmployee ID : ", node->data->employeeId;
        cout<<"\nName        : ", node->data->name;
        cout<<"\nSalary      : ", node->data->salary;
        inorder(node->right);
    }

    EmployeeNode* searchNode(EmployeeNode* node, int id)
    {
        if(node == NULL)
            return NULL;

        if(node->data->employeeId == id)
            return node;
        else if(id < node->data->employeeId)        
            return searchNode(node->left, id);        
        else 
            return searchNode(node->right, id);        
    }

    int count(EmployeeNode* node)
    {
        if(node == NULL)
            return 0;
        
        return 1 + count(node->left) + count(node->right);
    }


    EmployeeNode* min(EmployeeNode* node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;     
    }
    EmployeeNode* deletenode(EmployeeNode* node, int id)
    {
        if(node == NULL)
            return NULL;
        if(id < node->data->employeeId)
            node->left = deletenode(node->left, id);
        else if(id > node->data->employeeId)
            node->right = deletenode(node->right, id);
        else if(id == node->data->employeeId)
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            if (node->left != NULL && node->right == NULL)
            {
                EmployeeNode* temp = node->left;
                delete node;
                return temp;
            }            
            if (node->left == NULL && node->right != NULL)
            {
                EmployeeNode* temp = node->right;
                delete node;
                return temp;
            }            
            EmployeeNode* temp = min(node->right);
            node->data = temp->data;
            node->right = deletenode(node->right, temp->data->employeeId);
        }
        return node;
    }    
    

    EmployeeNode* searchbyname(EmployeeNode* node,char name[])
    {
    if (node == NULL)
        return NULL;

    bool same = true;
    int i = 0;
    while (node->data->name[i] != '\0' || name[i] != '\0')
    {
        if (node->data->name[i] != name[i])
        {
            same = false;
            break;
        }
        i++;   
    }
    if(same)
        return node;

    EmployeeNode* temp = searchbyname(node->left, name);
    if (temp != NULL)
        return temp;

    return searchbyname(node->right,name);
    }



public:
    EmployeeTree()
    {
        root = NULL;
    }
    void add(Employee* emp)
    {
        root = insert(root, emp);
    }
    void displayAll()
    {
        inorder(root);
    }
    EmployeeNode* search(int id)
    {
        return searchNode(root, id);
    }
    int getCount()
    {
        return count(root);
    }
    EmployeeNode* getRoot()
    {
        return root;
    }
    void removenode(int employeeid)
    {
        root = deletenode(root, employeeid);
    }

    EmployeeNode* searchbyname(char name[])
    {
        return searchbyname(root, name);
    }
};


class  CustomerTree
{
private:

    CustomerNode* root;

    CustomerNode* insert(CustomerNode* node, Customer* cust)
    {
        if(node == NULL)
            return new CustomerNode(cust);
        if(cust->customerId < node->data->customerId)
            node->left = insert(node->left, cust);
        else if(cust->customerId > node->data->customerId)
            node->right = insert(node->right, cust);
        return node;
    }

    void inorder(CustomerNode* node)
    {
        if(node == NULL)
            return;

        inorder(node->left);
        cout<<"\nCustomer ID : ", node->data->customerId;
        cout<<"\nName        : ", node->data->name;
        cout<<"\nAddress     : ", node->data->address;
        inorder(node->right);
    }

    CustomerNode* searchNode(CustomerNode* node, int id)
    {
        if(node == NULL)
            return NULL;
        if(node->data->customerId == id)
            return node;
        if(id < node->data->customerId)
            return searchNode(node->left, id);
        return searchNode(node->right, id);
    }

    CustomerNode* min(CustomerNode* node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
        
    }

    CustomerNode* deletenode(CustomerNode* node, int id)
    {
        if(node == NULL)
            return NULL;

        if(id < node->data->customerId)
            node->left = deletenode(node->left, id);

        else if(id > node->data->customerId)
            node->right = deletenode(node->right, id);

        else
        {
           
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }

       
            if (node->left != NULL && node->right == NULL)
            {
                CustomerNode* temp = node->left;
                delete node;
                return temp;
            }
            
           
            if (node->left == NULL && node->right != NULL)
            {
                CustomerNode* temp = node->right;
                delete node;
                return temp;
            }
            

            CustomerNode* temp = min(node->right);
            node->data = temp->data;
            node->right = deletenode(node->right, temp->data->customerId);
        }
        return root;
    }    

    
    int count(CustomerNode* node)
    {
        if(node == NULL)
            return 0;

        return 1 + count(node->left) + count(node->right);
    }


public:
    CustomerTree()
    {
        root = NULL;
    }

    void add(Customer*cust)
    {
        root = insert(root, cust);
    }
    void displayAll()
    {
        inorder(root);
    }
    CustomerNode* search(int id)
    {
        return searchNode(root, id);
    }
    int getCount()
    {
        return count(root);
    }
    CustomerNode* getRoot()
    {
        return root;
    }
    void removenode(int customerid)
    {
        root = deletenode(root, customerid);
    }
};


class SaleTree
{
private:

    SaleNode* root;

    SaleNode* insert(SaleNode* node, Sale* sale)
    {
        if(node == NULL)
            return new SaleNode(sale);
        if(sale->saleId < node->data->saleId)
            node->left = insert(node->left, sale);
        else if(sale->saleId > node->data->saleId)
            node->right = insert(node->right, sale);
        return node;
    }

    void inorder(SaleNode* node)
    {
        if(node == NULL)
            return;

        inorder(node->left);
        cout<<"\nSale ID     : ", node->data->saleId;
        cout<<"\nEmployee ID : ", node->data->employeeId;
        cout<<"\nCustomer ID : ", node->data->customerId;
        cout<<"\nAmount      : ", node->data->amount;
        inorder(node->right);
    }

    
    SaleNode* searchNode(SaleNode* node, int id)
    {
        if(node == NULL)
            return NULL;
        if(node->data->saleId == id)
            return node;
        if(id < node->data->saleId)
            return searchNode(node->left, id);
        return searchNode(node->right, id);
    }

   
    SaleNode* min(SaleNode* node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
        
    }

    SaleNode* deletenode(SaleNode* node, int id)
    {
        if(node == NULL)
            return NULL;

        if(id < node->data->saleId)
            node->left = deletenode(node->left, id);

        else if(id > node->data->saleId)
            node->right = deletenode(node->right, id);

        else
        {
           
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }

       
            if (node->left != NULL && node->right == NULL)
            {
                SaleNode* temp = node->left;
                delete node;
                return temp;
            }
            
           
            if (node->left == NULL && node->right != NULL)
            {
                SaleNode* temp = node->right;
                delete node;
                return temp;
            }           
            
            SaleNode* temp = min(node->right);
            node->data = temp->data;
            node->right = deletenode(node->right, temp->data->saleId);
        }
        return root;
    }   


    int count(SaleNode* node)
    {
        if(node == NULL)
            return 0;

        return 1 + count(node->left) + count(node->right);
    }

   
public:
    SaleTree()
    {
        root = NULL;
    }

    void add(Sale* sale)
    {
        root = insert(root, sale);
    }
    void displayAll()
    {
        inorder(root);
    }
    SaleNode* search(int saleid)
    {
        return searchNode(root, saleid);
    }
    int getCount()
    {
        return count(root);
    }
    SaleNode* getRoot()
    {
        return root;
    }
    void removenode(int saleid)
    {
        root = deletenode(root, saleid);
    }
};





void addEmployee(EmployeeTree& employeeTree)
{
    Employee* emp = new Employee;

    while (true)
    {
    cout<<"\nEnter Employee ID : ";
    cin>>emp->employeeId;
    if (cin.fail())
    {
        cout<<"Invalid input. enter only numbers \n";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    else
    {
        break;
    }
    }

    if(employeeTree.search(emp->employeeId) != NULL)
    {
        cout<<"\nEmployee ID already exists\n";
        return;
    }

    cout<<"Enter Employee Name : ";
    cin.ignore();
    cin.getline(emp->name, 50);

    while (true)
    {
    cout<<"Enter Salary : ";                                          
    cin>>emp->salary;
    if (cin.fail())
    {
        cout<<"invalid salary.enter only nums \n";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    else{
        break;
    }
    
    }

    employeeTree.add(emp);

    cout<<"\nEmployee Added \n";
}


void addCustomer(CustomerTree& customerTree)
{
    Customer* cust = new Customer;
    while (true)
    {
    cout<<"\nEnter Customer ID : ";
    cin>>cust->customerId;
        if (cin.fail())
        {
            cout<<"invalid.enter only nums\n";
            cin.clear();
            cin.ignore(1000,'\n');
        }
        else
        {
            break;
        }       
    }
    if(customerTree.search(cust->customerId) != NULL)
    {
        cout<<"\nCustomer ID already exists\n";
        return;
    }

    cout<<"Enter Customer Name : ";
    cin.ignore();
    cin.getline(cust->name, 50);
    cout<<"Enter Customer Address : ";
    cin.ignore();
    cin.getline(cust->address, 100);

    customerTree.add(cust);

    cout<<"\nCustomer Added \n";
}


void addSale( SaleTree& saleTree, EmployeeTree& employeeTree, CustomerTree& customerTree)
{
    Sale* sale = new Sale;
    while (true)
    {
       
    cout<<"\nEnter Sale ID : ";
    cin>>sale->saleId;
    if (cin.fail())
    {
        cout<<"invalid. enter only nums";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    else
        break;
    }

    while (saleTree.search(sale->saleId) != NULL)
    {
        cout<<"\nSale isid already exists\n";
        cout<<"\nEnter Sale ID : ";
        cin>>sale->saleId;

    }
    
    while (true)
    {
       
    cout<<"Enter Employee ID : ";
    cin>>sale->employeeId;
    if (cin.fail())
    {
        cout<<"invalid. enter only nums";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    else
        break;

}   

    
    if(employeeTree.search(sale->employeeId) == NULL)
    {
        cout<<"\nEmployee Not Found\n";
        return;
    }

    while (true)
    {

    cout<<"Enter Customer ID : ";
    cin>>sale->customerId;
    if (cin.fail())
    {
        cout<<"invalid. enter nums only";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    else
        break;
    }
  
    if(customerTree.search(sale->customerId) == NULL)
    {
        cout<<"\nCustomer Not Found!\n";
        return;
    }

    while (true)
    {
        
    cout<<"Enter Sale Amount: ";
    cin>>sale->amount;
    if (cin.fail())
    {
        cout<<"invalid. enter only nums";
        cin.clear();
        cin.ignore(100000,'\n');
    }
    else
        break;
}
    

    saleTree.add(sale);

    cout<<"\nSale Added \n";
}




void deleteEmp(EmployeeTree& employeeTree)
{
    int employeeid;

    while (true)
    {   
    cout<<"\nEner id to delete: ";
    cin>>employeeid;
    if (cin.fail())
    {
        cout<<"invalid. enter nums only";
        cin.clear();
        cin.ignore(1000,'\n');
    } 
    else
        break;
    }

    if (employeeTree.search(employeeid) == NULL)
    {
        cout<<"\nEmployee not found\n";
        return;
    }

    employeeTree.removenode(employeeid);
    cout<<"\nEmployee deleted\n"; 
}

void deleteCust(CustomerTree& customerTree)
{
    int customerid;

    while (true)
    {
    cout<<"\nEnter id to delete: ";
    cin>>customerid;
    if (cin.fail())
    {
        cout<<"invalid. enter only nums";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    else
        break;
    
    }

    if (customerTree.search(customerid) == NULL)
    {
        cout<<"\ncustomer not found\n";
        return;
    }

    customerTree.removenode(customerid);
    cout<<"\nCustomer deleted\n";
}

void deleteSale(SaleTree& saleTree)
{
    int saleid;

    while (true)
    {
    cout<<"\nEnter id to delete: ";
    cin>>saleid;
    if (cin.fail())
    {
        cout<<"invalid. enter nums only";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    else
        break;
    }

    if (saleTree.search(saleid) == NULL)
    {
        cout<<"\nsale not found\n";
        return;
    }

    saleTree.removenode(saleid);
    cout<<"\nSale deleted\n";
    
}




void serializeEmp(EmployeeNode* node, FILE* fp)
{
    if(node == NULL)
        return;

    serializeEmp(node->left, fp);
    fwrite((node->data), sizeof(Employee), 1, fp);                
    serializeEmp(node->right, fp);
}


void serializeCust(CustomerNode* node, FILE* fp)
{
    if(node == NULL)
        return;

    serializeCust(node->left, fp);
    fwrite( (node->data), sizeof(Customer), 1, fp);                  
    serializeCust(node->right, fp);
}


void serializeSales(SaleNode* node, FILE* fp)
{
    if(node == NULL)
        return;

    serializeSales(node->left, fp);
    fwrite( (node->data), sizeof(Sale), 1, fp);  
    serializeSales(node->right, fp);
}



void saveData( EmployeeTree& employeeTree, CustomerTree& customerTree, SaleTree& saleTree)
{
    FILE*fp = fopen("Data.bin", "wb");

    if(fp == NULL)
    {
        cout<<"\nError Creating File\n";
        return;
    }

    int employeeCount = employeeTree.getCount();
    int customerCount = customerTree.getCount();
    int saleCount = saleTree.getCount();

    fwrite(&employeeCount, sizeof(int), 1, fp);
    fwrite(&customerCount, sizeof(int), 1, fp);
    fwrite(&saleCount, sizeof(int), 1, fp);

    serializeEmp(employeeTree.getRoot(), fp);
    serializeCust(customerTree.getRoot(), fp);
    serializeSales(saleTree.getRoot(), fp);

    fclose(fp);

    cout<<"\nData Saved \n";
}


           


void deseriEmp(FILE* fp, EmployeeTree& employeeTree, int employeeCount)
{
    Employee* emp = new Employee;

    for(int i = 0; i < employeeCount; i++)
    {
        fread(emp, sizeof(Employee), 1, fp);
        employeeTree.add(emp);
    }
}


void deseriCust(FILE* fp, CustomerTree& customerTree, int customerCount)
{
    Customer* cust = new Customer;

    for(int i = 0; i < customerCount; i++)
    {
        fread( cust, sizeof(Customer), 1, fp);
        customerTree.add(cust);
    }
}


void deseriSales(FILE* fp, SaleTree& saleTree, int saleCount)
{
    Sale* sale = new Sale;

    for(int i = 0; i < saleCount; i++)
    {
        fread(sale, sizeof(Sale), 1, fp);
        saleTree.add(sale);
    }
}



void loadData( EmployeeTree& employeeTree, CustomerTree& customerTree, SaleTree& saleTree)
{
    FILE* fp = fopen("Data.bin", "rb");

    if(fp == NULL)
    {
        return;
    }

    int employeeCount;
    int customerCount;
    int saleCount;

    fread( &employeeCount, sizeof(int), 1, fp);
    fread(&customerCount, sizeof(int), 1, fp);
    fread( &saleCount, sizeof(int), 1, fp);

    deseriEmp( fp, employeeTree, employeeCount);
    deseriCust(fp, customerTree, customerCount);
    deseriSales(fp, saleTree, saleCount);

    fclose(fp);

    cout<<"\nData Loaded \n";
}




class CustomerSummary
{
public:

    int customerId;
    char customerName[50];
    int saleCount;
    float totalAmount;

    CustomerSummary()
    {
        customerId = 0;
        saleCount = 0;
        totalAmount = 0;
        (customerName, "");
    }
};




void displayEmployeeSales( SaleNode* node, int employeeId, CustomerTree& customerTree, CustomerSummary summary[], int& summaryCount)
{
    if(node == NULL)
        return;

    displayEmployeeSales( node->left, employeeId, customerTree, summary, summaryCount);

    if(node->data->employeeId == employeeId)
    {
        cout<<"\n------------------------";
        cout<<"\nSale ID     : ", node->data->saleId;
        cout<<"\nCustomer ID : ", node->data->customerId;
        cout<<"\nAmount      : ", node->data->amount;

        bool found = false;

        for(int i = 0; i < summaryCount; i++)
        {
            if(summary[i].customerId == node->data->customerId)
            {
                found = true;
                break;
            }
        }

        if(!found)
        {
            summary[summaryCount].customerId = node->data->customerId;
            CustomerNode* cust = customerTree.search( node->data->customerId );

            if(cust != NULL)
            {
                ( summary[summaryCount].customerName, cust->data->name);
            }

            summary[summaryCount].saleCount = 1;
            summary[summaryCount].totalAmount = node->data->amount;
            summaryCount++;
        }
    }           

    displayEmployeeSales( node->right, employeeId, customerTree, summary, summaryCount);
}



void employeeReport(EmployeeTree& employeeTree, CustomerTree& customerTree, SaleTree& saleTree)
{
    char employeename[50];

    cout<<"\nEnter Employee Name : ";
    cin>>employeename;
    cin.ignore();
    cin.getline(employeename, 50);

    EmployeeNode* emp = employeeTree.searchbyname(employeename);

    if(emp == NULL)
    {
        cout<<"\nEmployee Not Found!\n";
        return;
    }
    int employeeId = emp->data->employeeId;

    cout<<"\nEmployee Details";
    cout<<"\n-----------------";

    cout<<"\nEmployee ID : ", emp->data->employeeId;
    cout<<"\nName        : ", emp->data->name;
    cout<<"\nSalary      : ", emp->data->salary;

    CustomerSummary summary[100];

    int summaryCount = 0;

    cout<<"\n\n------- SALES -------\n";
    displayEmployeeSales( saleTree.getRoot(), employeename[25], customerTree, summary, summaryCount);

    cout<<"\n\n------- CUSTOMER SUMMARY -------\n";
    for(int i = 0; i < summaryCount; i++)
    {
        cout<<"\nCustomer ID   : ", summary[i].customerId;
        cout<<"\nCustomer Name : ", summary[i].customerName;
        cout<<"\nSales Count   : ", summary[i].saleCount;
        cout<<"\nTotal Amount  : ", summary[i].totalAmount;
        cout<<"\n-----------------------";
    }
}







int main()
{
    EmployeeTree employeeTree;
    CustomerTree customerTree;
    SaleTree saleTree;

    loadData( employeeTree, customerTree, saleTree);

    int choice;

    while(true)
    {
        cout<<"\n===SALES MANAGEMENT SYSTEM===\n";
        cout<<"\n1. Add Employee";
        cout<<"\n2. Add Customer";
        cout<<"\n3. Add Sale";
        cout<<"\n4. Display Employees";
        cout<<"\n5. Display Customers";
        cout<<"\n6. Display Sales";
        cout<<"\n7. Employee Report";
        cout<<"\n8. Save Database";
        cout<<"\n9.  Delete employee";
        cout<<"\n10. Delete Customer";
        cout<<"\n11. Delete sales";
        cout<<"\n12. Exit";
        cout<<"\n----------------------------";
        cout<<"\nEnter Your Choice : ";
        cin>>choice;
        cout<<"\n";


        switch(choice)
        {
        case 1:
            addEmployee(employeeTree);
            break;

        case 2:
            addCustomer(customerTree);
            break;

        case 3:
            addSale( saleTree, employeeTree, customerTree);
            break;

        case 4:
            employeeTree.displayAll();
            break;

        case 5:
            customerTree.displayAll();
            break;

        case 6:
            saleTree.displayAll();
            break;

        case 7:
            employeeReport( employeeTree, customerTree, saleTree);
            break;

        case 8:
            saveData( employeeTree, customerTree, saleTree);
            break;

        case 9:
            deleteEmp(employeeTree);
            break;
          
        case 10:
            deleteCust(customerTree);
            break;

        case 11:
            deleteSale(saleTree);
            break;

        case 12:
            saveData(employeeTree, customerTree, saleTree);
            cout<<"\nProgram exit\n\n";
            return false;

        default:
            cout<<"\nInvalid Choice!\n";
        }
    }
}
