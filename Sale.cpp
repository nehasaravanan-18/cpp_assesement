#include <stdio.h>
#include <string.h>
                                 

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
        strcpy(name, "");
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
    Employee data;
    EmployeeNode* left;
    EmployeeNode* right;

    EmployeeNode(Employee emp)
    {
        data = emp;
        left = NULL;
        right = NULL;
    }
};


class CustomerNode
{
public:
    Customer data;
    CustomerNode* left;
    CustomerNode* right;

    CustomerNode(Customer cust)
    {
        data = cust;
        left = NULL;
        right = NULL;
    }
};


class SaleNode
{
public:
    Sale data;
    SaleNode* left;
    SaleNode* right;

    SaleNode(Sale sale)
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

    EmployeeNode* insert(EmployeeNode* node, Employee emp)
    {
        if(node == NULL)
            return new EmployeeNode(emp);
        if(emp.employeeId < node->data.employeeId)
            node->left = insert(node->left, emp);
        else if(emp.employeeId > node->data.employeeId)
            node->right = insert(node->right, emp);
        return node;
    }

    void inorder(EmployeeNode* node)
    {
        if(node == NULL)
            return;

        inorder(node->left);
        printf("\nEmployee ID : %d", node->data.employeeId);
        printf("\nName        : %s", node->data.name);
        printf("\nSalary      : %.2f\n", node->data.salary);
        inorder(node->right);
    }

    EmployeeNode* searchNode(EmployeeNode* node, int id)
    {
        if(node == NULL)
            return NULL;

        if(node->data.employeeId == id)
            return node;
        if(id < node->data.employeeId)
            return searchNode(node->left, id);
        return searchNode(node->right, id);
    }

    int count(EmployeeNode* node)
    {
        if(node == NULL)
            return 0;

        return 1 + count(node->left) + count(node->right);
    }


    void deletetree(EmployeeNode* node)
    {
        if (node == NULL)
        
            return;
        
            deletetree(node->left);
            deletetree(node->right);

            delete node;  
            printf("\nEmployeeTRee deleted\n"); 
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

        if(id < node->data.employeeId)
            node->left = deletenode(node->left, id);

        else if(id > node->data.employeeId)
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
            node->right = deletenode(node->right, temp->data.employeeId);
        }
    }    


public:
    EmployeeTree()
    {
        root = NULL;
    }

    void add(Employee emp)
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
    void removetree()
    {
        deletetree(root);
        root = NULL;
    }
    void removenode(int employeeid)
    {
        root = deletenode(root, employeeid);
    }
};


class  CustomerTree
{
private:

    CustomerNode* root;

    CustomerNode* insert(CustomerNode* node, Customer cust)
    {
        if(node == NULL)
            return new CustomerNode(cust);
        if(cust.customerId < node->data.customerId)
            node->left = insert(node->left, cust);
        else if(cust.customerId > node->data.customerId)
            node->right = insert(node->right, cust);
        return node;
    }

    void inorder(CustomerNode* node)
    {
        if(node == NULL)
            return;

        inorder(node->left);
        printf("\nCustomer ID : %d", node->data.customerId);
        printf("\nName        : %s", node->data.name);
        printf("\nAddress     : %s\n", node->data.address);
        inorder(node->right);
    }

    CustomerNode* searchNode(CustomerNode* node, int id)
    {
        if(node == NULL)
            return NULL;
        if(node->data.customerId == id)
            return node;
        if(id < node->data.customerId)
            return searchNode(node->left, id);
        return searchNode(node->right, id);
    }

    void deletetree (CustomerNode* node)
    {
        if (node == NULL)
            return;

        deletetree(node->left);
        deletetree(node->right);

        delete node;
        printf("\nCustomerTRee deleted\n");
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

        if(id < node->data.customerId)
            node->left = deletenode(node->left, id);

        else if(id > node->data.customerId)
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
            node->right = deletenode(node->right, temp->data.customerId);
        }
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

    void add(Customer cust)
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
    void removetree()
    {
        deletetree(root);
        root = NULL;
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

    SaleNode* insert(SaleNode* node, Sale sale)
    {
        if(node == NULL)
            return new SaleNode(sale);
        if(sale.saleId < node->data.saleId)
            node->left = insert(node->left, sale);
        else if(sale.saleId > node->data.saleId)
            node->right = insert(node->right, sale);
        return node;
    }

    void inorder(SaleNode* node)
    {
        if(node == NULL)
            return;

        inorder(node->left);
        printf("\nSale ID     : %d", node->data.saleId);
        printf("\nEmployee ID : %d", node->data.employeeId);
        printf("\nCustomer ID : %d", node->data.customerId);
        printf("\nAmount      : %.2f", node->data.amount);
        inorder(node->right);
    }

    
    SaleNode* searchNode(SaleNode* node, int id)
    {
        if(node == NULL)
            return NULL;
        if(node->data.saleId == id)
            return node;
        if(id < node->data.saleId)
            return searchNode(node->left, id);
        return searchNode(node->right, id);
    }

    void deletetree (SaleNode* node)
    {
        if (node == NULL)
            return;

        deletetree(node->left);
        deletetree(node->right);

        delete node;
        printf("\nSaleTRee deleted\n");
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

        if(id < node->data.saleId)
            node->left = deletenode(node->left, id);

        else if(id > node->data.saleId)
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
            node->right = deletenode(node->right, temp->data.saleId);
        }
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

    void add(Sale sale)
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
    void removetree()
    {
        deletetree(root);
        root = NULL;
    }
    void removenode(int saleid)
    {
        root = deletenode(root, saleid);
    }
};





void addEmployee(EmployeeTree& employeeTree)
{
    Employee emp;

    printf("\nEnter Employee ID : ");
    scanf("%d", &emp.employeeId);

    if(employeeTree.search(emp.employeeId) != NULL)
    {
        printf("\nEmployee ID already exists\n");
        return;
    }

    printf("Enter Employee Name : ");
    scanf("%49s", emp.name);
    printf("Enter Salary : ");
    scanf("%f", &emp.salary);

    employeeTree.add(emp);

    printf("\nEmployee Added \n");
}


void addCustomer(CustomerTree& customerTree)
{
    Customer cust;

    printf("\nEnter Customer ID : ");
    scanf("%d", &cust.customerId);

    if(customerTree.search(cust.customerId) != NULL)
    {
        printf("\nCustomer ID already exists\n");
        return;
    }

    printf("Enter Customer Name : ");
    scanf("%49s", cust.name);
    printf("Enter Customer Address : ");
    scanf("%99s", cust.address);

    customerTree.add(cust);

    printf("\nCustomer Added \n");
}


void addSale( SaleTree& saleTree, EmployeeTree& employeeTree, CustomerTree& customerTree)
{
    Sale sale;

    printf("\nEnter Sale ID : ");
    scanf("%d", &sale.saleId);
    
    if (saleTree.search(sale.saleId) != NULL)
    {
        printf("\nSale id already exists");
    }
    
    printf("Enter Employee ID : ");
    scanf("%d", &sale.employeeId);

    
    if(employeeTree.search(sale.employeeId) == NULL)
    {
        printf("\nEmployee Not Found\n");
        return;
    }

    printf("Enter Customer ID : ");
    scanf("%d", &sale.customerId);

  
    if(customerTree.search(sale.customerId) == NULL)
    {
        printf("\nCustomer Not Found!\n");
        return;
    }

    printf("Enter Sale Amount : ");
    scanf("%f", &sale.amount);

    saleTree.add(sale);

    printf("\nSale Added \n");
}





void serializeEmp(EmployeeNode* node, FILE* fp)
{
    if(node == NULL)
        return;

    serializeEmp(node->left, fp);
    fwrite( &(node->data), sizeof(Employee), 1, fp);                
    serializeEmp(node->right, fp);
}


void serializeCust(CustomerNode* node, FILE* fp)
{
    if(node == NULL)
        return;

    serializeCust(node->left, fp);
    fwrite( &(node->data), sizeof(Customer), 1, fp);                  
    serializeCust(node->right, fp);
}


void serializeSales(SaleNode* node, FILE* fp)
{
    if(node == NULL)
        return;

    serializeSales(node->left, fp);
    fwrite( &(node->data), sizeof(Sale), 1, fp);  
    serializeSales(node->right, fp);
}



void saveData( EmployeeTree& employeeTree, CustomerTree& customerTree, SaleTree& saleTree)
{
    FILE* fp = fopen("Data.bin", "wb");

    if(fp == NULL)
    {
        printf("\nError Creating File\n");
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

    printf("\nData Saved \n");
}






void deseriEmp(FILE* fp, EmployeeTree& employeeTree, int employeeCount)
{
    Employee emp;

    for(int i = 0; i < employeeCount; i++)
    {
        fread( &emp, sizeof(Employee), 1, fp);
        employeeTree.add(emp);
    }
}


void deseriCust(FILE* fp, CustomerTree& customerTree, int customerCount)
{
    Customer cust;

    for(int i = 0; i < customerCount; i++)
    {
        fread( &cust, sizeof(Customer), 1, fp);
        customerTree.add(cust);
    }
}


void deseriSales(FILE* fp, SaleTree& saleTree, int saleCount)
{
    Sale sale;

    for(int i = 0; i < saleCount; i++)
    {
        fread( &sale, sizeof(Sale), 1, fp);
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

    printf("\nData Loaded \n");
}



void deleteEmp(EmployeeTree& employeeTree)
{
    int employeeid;

    printf("\nEner id to delete: ");
    scanf("%d", &employeeid);

    if (employeeTree.search(employeeid) == NULL)
    {
        printf("\nEmployee not found\n");
        return;
    }

    employeeTree.removenode(employeeid);
    printf("\nEmployee deleted\n");  
}

void deleteCust(CustomerTree& customerTree)
{
    int customerid;

    printf("\nEnter id to delete: ");
    scanf("%d", &customerid);

    if (customerTree.search(customerid) == NULL)
    {
        printf("\ncustomer not found\n");
        return;
    }

    customerTree.removenode(customerid);
    printf("\nCustomer deleted\n");
}

void deleteSale(SaleTree& saleTree)
{
    int saleid;

    printf("\nEnter id to delete: ");
    scanf("%d", &saleid);

    if (saleTree.search(saleid) == NULL)
    {
        printf("\nsale not found\n");
        return;
    }

    saleTree.removenode(saleid);
    printf("\nSale deleted\n");
    
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
        strcpy(customerName, "");
    }
};




void displayEmployeeSales( SaleNode* node, int employeeId, CustomerTree& customerTree, CustomerSummary summary[], int& summaryCount)
{
    if(node == NULL)
        return;

    displayEmployeeSales( node->left, employeeId, customerTree, summary, summaryCount);

    if(node->data.employeeId == employeeId)
    {
        printf("\n------------------------");
        printf("\nSale ID     : %d", node->data.saleId);
        printf("\nCustomer ID : %d", node->data.customerId);
        printf("\nAmount      : %.2f", node->data.amount);

        bool found = false;

        for(int i = 0; i < summaryCount; i++)
        {
            if(summary[i].customerId == node->data.customerId)
            {
                found = true;
                break;
            }
        }

        if(!found)
        {
            summary[summaryCount].customerId = node->data.customerId;
            CustomerNode* cust = customerTree.search( node->data.customerId );

            if(cust != NULL)
            {
                strcpy( summary[summaryCount].customerName, cust->data.name);
            }

            summary[summaryCount].saleCount = 1;
            summary[summaryCount].totalAmount = node->data.amount;
            summaryCount++;
        }
    }

    displayEmployeeSales( node->right, employeeId, customerTree, summary, summaryCount);
}



void employeeReport(EmployeeTree& employeeTree, CustomerTree& customerTree, SaleTree& saleTree)
{
    int employeeId;

    printf("\nEnter Employee ID : ");
    scanf("%d", &employeeId);

    EmployeeNode* emp = employeeTree.search(employeeId);

    if(emp == NULL)
    {
        printf("\nEmployee Not Found!\n");
        return;
    }

    printf("\nEmployee Details");
    printf("\n-----------------");

    printf("\nEmployee ID : %d", emp->data.employeeId);
    printf("\nName        : %s", emp->data.name);
    printf("\nSalary      : %.2f", emp->data.salary);

    CustomerSummary summary[100];

    int summaryCount = 0;

    printf("\n\n------- SALES -------\n");
    displayEmployeeSales( saleTree.getRoot(), employeeId, customerTree, summary, summaryCount);

    printf("\n\n------- CUSTOMER SUMMARY -------\n");
    for(int i = 0; i < summaryCount; i++)
    {
        printf("\nCustomer ID   : %d", summary[i].customerId);
        printf("\nCustomer Name : %s", summary[i].customerName);
        printf("\nSales Count   : %d", summary[i].saleCount);
        printf("\nTotal Amount  : %.2f", summary[i].totalAmount);
        printf("\n-----------------------");
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

        printf("\n===SALES MANAGEMENT SYSTEM===\n");
        printf("\n1. Add Employee");
        printf("\n2. Add Customer");
        printf("\n3. Add Sale");
        printf("\n4. Display Employees");
        printf("\n5. Display Customers");
        printf("\n6. Display Sales");
        printf("\n7. Employee Report");
        printf("\n8. Save Database");
        printf("\n9. Delete empTree");
        printf("\n10. Delete custTree");
        printf("\n11. Delete SaleTree");
        printf("\n12. Delete employee");
        printf("\n13. Delete Customer");
        printf("\n14. Delete sales");
        printf("\n15. Exit");
        printf("\n----------------------------");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        printf ("\n");


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
            employeeTree.removetree();         
            break;

        case 10:
            customerTree.removetree();
            break;

        case 11:
            saleTree.removetree();
            break;

        case 12:
            deleteEmp(employeeTree);
            break;
          
        case 13:
            deleteCust(customerTree);
            break;

        case 14:
            deleteSale(saleTree);
            break;

        case 15:
            saveData(employeeTree, customerTree, saleTree);
            printf("\nProgram exit\n\n");
            return false;

        default:
            printf("\nInvalid Choice!\n");
        }
    }
}