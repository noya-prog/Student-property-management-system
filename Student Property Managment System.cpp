#include<iostream>
#include<cstring>
#include<windows.h>
using namespace std;
void menu();
void add_beginning();
void add_ending();
void add_anywhere();
void display();
void delete_beginning();
void delete_ending();
void delete_anywhere();
void search_id();
void search_serialnumber();
void sort_byname();
void update();
struct secure{
	char name[20];
	char last_name[20];
	char id[20];
	char serial_number[20];
	char brand[20];
	secure*next;
};
secure*head=NULL;
int nos=0;
int main()
{
	
	system("color b");
	a:
	menu();
	int n;
	cout<<endl<<"Please enter your choice!"<<endl;
	cin>>n;
	cout<<endl;
	while(n!=0){
	
	switch (n)
	{
		case 1:
			add_beginning();
			break;
		case 2:
		    add_ending();
		    break;
		case 3:
		    add_anywhere();
			break;    
		case 4:
			delete_beginning();
			break;
		case 5:
			delete_ending();
			break;
		case 6:
			delete_anywhere();
			break;
		case 7:
			search_serialnumber();
			break;
		case 8:
			search_id();
			break;
		case 9:
			sort_byname();
			break;
		case 10:
			update();
			break;
		case 11:
			display();
			break;
		
		defualt:
			cout<<"please change your choice"<<endl;
				
	}
	goto a;
}
	return 0;
	
}
void menu()
{

	cout<<"\t\t\tENKUAN WEDE BDU BESELAM METU\n"<<endl;
	cout<<"--------------------------------------------------------------------------------\n";
	cout<<" \t\tpress 1 to add in the beginning"<<endl;
    cout<<" \t\tPress 2 to add at the ending"<<endl;                         
    cout<<" \t\tPress 3 to add anywhere"<<endl;                                                                                                    
    cout<<" \t\tPress 4 to delete in the beginning"<<endl;                      
    cout<<" \t\tPress 5 to delete at the ending"<<endl;                                                                            
    cout<<" \t\tPress 6 to delete anywhere"<<endl;                      
    cout<<" \t\tPress 7 to search by serialnumber"<<endl;                         
    cout<<" \t\tPress 8 to search by student id"<<endl;  
	cout<<" \t\tpress 9 to sort student info"<<endl;
	cout<<" \t\tpress 10 to update student info"<<endl;
	cout<<" \t\tpress 11 to display student info"<<endl;                                                                                            
    cout<<" \t\tpress 0 to exit"<<endl;        
}
void add_beginning(){
	
  secure*student = new secure;
  student->next=NULL;
  cout<<"\nAdd at the beginning\n\n";
  cout << "  Enter the Name of the student:          -----> ";
  cin >> student->name;
  cout << "  Enter the last Name of the student:     -----> ";
  cin >> student->last_name;
  cout << "  Please enter the ID of the student:     -----> ";
  cin >> student->id;
  cout << "  Please enter the PC serial number:      -----> ";
  cin >> student->serial_number;
  cout << "  Please enter PC brand:                  -----> ";
  cin>>student->brand;
  
  if(head==NULL){
 head=student;
  nos++;
  
  }
  else{
  student->next=head;
  head=student;
  nos++;
}
 cout<<"Successfully added"<<endl;
}

void add_ending()
{
  
  secure*student1=new secure;

  student1->next=NULL;
  cout<<"\nINSERT AT THE ENDING  \n\n";
  cout << "  Enter the Name of the student:       ------>";
  cin >> student1->name;
  cout << "  Enter the last Name of the student:  ------>";
  cin >> student1->last_name;
  cout << "  Please enter the ID of the student:  ------>";
  cin >> student1->id;
  cout << "  Please enter the PC serial number:   ------>";
  cin >> student1->serial_number;
  cout << "  Please enter brand:                  ------>";
  cin>>student1->brand;

  if(head==NULL)
  {
 head=student1;
 
 nos++;
  }
  else
{
secure*temp1=head;
while(temp1->next!=NULL){
	temp1=temp1->next;
}
temp1->next=student1;
nos++;
}
 cout<<"Successfully added"<<endl;

}
void add_anywhere(){
secure*student2=new secure;
student2->next=NULL;
  cout<<"\nAdd anywhere\n\n";
  cout << "  Enter the Name of the student:      ------->";
  cin >> student2->name;
  cout << "  Enter the last Name of the student: ------->";
  cin >> student2->last_name;
  cout << "  Please enter the ID of the student: ------->";
  cin >> student2->id;
  cout << "  Please enter the PC serial number:  ------->";
  cin >> student2->serial_number;
  cout << "  Please enter brand:                 ------->";
  cin >> student2->brand;
	secure*temp=head;
	int position;
	cout<<"Please enter the position to add"<<endl;
	cin>>position;
	if(position==1){
		if(head==NULL){
			head=student2;
			nos++;
			cout<<"Successfully added"<<endl;
		}
		else{
			student2->next=head;
			head=student2;
			nos++;
			cout<<"Successfully added"<<endl;
		}
	}
	else{
	if(position>nos+1){
	cout<<"Please adjust your position again"<<endl;

}
else{
		for(int i=1;i<position-1;i++){
		temp=temp->next;
	}
	student2->next=temp->next;
	temp->next=student2;
	nos++;
	cout<<"Successfully added"<<endl;
	
}
}
}

void delete_beginning(){
	char a;
	if(head==NULL)
		cout<<"Empty list"<<endl<<endl;
	else{
		cout<<"Are you sure to delete press y to delete/press n to continue"<<endl;
		cin>>a;
    	if(a=='y'||a=='Y'){
    	secure*temp=head;
		head=head->next;
		delete temp;
		nos--;
		cout<<"Successfuly deleted"<<endl<<endl;
	}
	else{
		if(a=='n'||a=='N'){
		cout<<"Not deleted"<<endl;
		}
		else
	cout<<"Wrong entry"<<endl;
	}
		
	}
}
void delete_ending(){
	char a;
	secure*current;
	if(head==NULL){
		cout<<"Empty list"<<endl<<endl;
	}
	else{
	cout<<"Are you sure to delete press y to delete/press n to continue"<<endl;
	cin>>a;
		if(a=='y'||a=='Y'){
	
	if(head->next==NULL){
	current=head;
	head=NULL;
	delete current;
	nos--;
	cout<<"Successfuly deleted"<<endl;
	
	}
	else{
		current=head;
		secure*previous=NULL;
		while(current->next!=NULL){
			previous=current;
			current=current->next;
		}
		previous->next=NULL;
		delete current;
		nos--;
		cout<<"Successfuly deleted"<<endl;
	
	}
}
else{
	if(a=='n'||a=='N'){
		cout<<"Not deleted"<<endl;
	}
	else
	cout<<"Wrong entry"<<endl;
}
}
}

void delete_anywhere(){
int position;
if(head==NULL){
	cout<<"Empty list"<<endl;	
}
else{ 
secure*current;
secure*previous;
cout<<"Please enter the position to delete"<<endl;
cin>>position;
if(position==1){
	current=head;
	head=head->next;
	delete current;
	nos--;
	cout<<"Successfuly deleted"<<endl<<endl;
}
else{
if(position>nos){
	cout<<endl<<"Please adjust your position again !!!"<<endl<<endl;
}
else{
	current=head;
	for(int i=0;i<position-1;i++){
		previous=current;
		current=current->next;
	}
	previous->next=current->next;
	delete current;
	nos--;
	cout<<"Successfuly deleted"<<endl;
	cout<<endl;
}
}
}
}
void search_id(){
	string s_id;
	int found=0;
	
 if(head==NULL)
 cout<<"Empty list"<<endl;
 else{
 	cout<<"\nSearch by Id\n";
 cout<<" Enter student Id for searching: ----->";
 cin>>s_id;
 
 for(secure*i=head;i!=NULL;i=i->next)
 {
 if(i->id==s_id)
 {
 cout<<" First name:      ---->  "<<i->name<<endl;
 cout<<" Last name:       ---->  "<<i->last_name<<endl;
 cout<<" Student Id:      ---->  "<<i->id<<endl;
 cout<<" Serial number:   ---->  "<<i->serial_number<<endl;
 cout<<" PC Brand:        ---->  "<<i->brand<<endl;
  found=1;
  break;
 }
 }
 if(found==0)
 cout<<"\n The searched id is not found in the list\n";
 else
 cout<<"\n The searched id is found in the list\n";	
   }
}
void search_serialnumber(){
	string serial_num;
	int found=0;
  
	if(head==NULL)
	cout<<"Empty list"<<endl;
	else{	
	cout<<"Enter serial number ---> ";
	cin>>serial_num;	
	secure*temp=head;
	while(temp!=NULL){
		if(temp->serial_number==serial_num){
		 cout<<" First name:      ---->  "<<temp->name<<endl;
         cout<<" Last name:       ---->  "<<temp->last_name<<endl;
         cout<<" Student Id:      ---->  "<<temp->id<<endl;
         cout<<" Serial number:   ---->  "<<temp->serial_number<<endl;
         cout<<" PC Brand:        ---->  "<<temp->brand<<endl;
  found=1;
  break;	
		}
		temp=temp->next;
	}
if(found==0)
 cout<<"\n The searched serial number is not found in the list\n";
 else
 cout<<"\n The searched serial number is found in the list\n";	

}
}
void sort_byname(){
	if(head==NULL){
		cout<<"There is no any data to be sorted"<<endl;
	}
	else{
	
for(secure *i=head;i->next!=NULL;i=i->next)
	{
		for(secure *j=i->next;j!=NULL;j=j->next)
		{
			if(strcmp(i->name,j->name)>0)
			{
				secure *temp=new secure;
				strcpy(temp->name,i->name);
				strcpy(temp->last_name,i->last_name);
			    strcpy(temp->id,i->id);
				strcpy(temp->serial_number,i->serial_number);
				
				strcpy(temp->brand,i->brand);
				strcpy(i->name,j->name);
				strcpy(i->last_name,j->last_name);
                strcpy(i->id,j->id);
		        strcpy(i->serial_number,j->serial_number);
				strcpy(i->brand,j->brand);
		      	strcpy(j->name,temp->name);
		      	strcpy(j->last_name,temp->last_name);
				strcpy(j->id,temp->id);
				strcpy(j->serial_number,temp->serial_number);
				strcpy(j->brand,temp->brand);
				
		   }
		}
	}
	cout<<"Successfully sorted"<<endl;
}
}
void update(){
	
   char choice;
   char new_serial_number[20];
   char new_brand[20];
   int alt;
   string ref_id;
   secure*temp=head;
   if(head==NULL)
   cout<<"There is no any record to be updated\n";
   else
    {
   cout<<"Enter the id of a student as reference: ------>";
   cin>>ref_id;
   while(temp->next!=NULL&&temp->id!=ref_id)
   {
    temp=temp->next;
    }
    if(temp->id==ref_id)
    {
  while(alt!=0){ 
   cout<<"Press 1 to update serial number of student \n";
   cout<<"Press 2 to update brand of student \n";
   cout<<"\n Enter your choice for your update :"<<endl;
   cin>>choice;
   cout<<" ----------------------------------------\n";
   if(choice=='1')
   {
   cout<<"Enter the new serial number :"<<endl;
   cin>>new_serial_number;
   strcpy(temp->serial_number,new_serial_number);
   cout<<"Successfully updated\n";
   }
  else
   if(choice=='2')
   {
   cout<<"Enter the new brand:"<<endl;
   cin>>new_brand;
   strcpy(temp->brand,new_brand);
   cout<<"Successfully updated\n";
   }

  else
  {
  cout<<"Please adjust your choice again!\n";
  }
   cout<<" press 0 to exit: "<<endl;
   cout<<" press any %number% if you want to update again"<<endl;
   cin>>alt;
}

}
else
cout<<"There is no any student with this id number"<<endl;
}
}
void display(){
	if(head==NULL){
		cout<<"Empty list"<<endl;
	}
	else{
	secure*temp=head;
	cout<<endl<<"Name\t\tLastname\t\t\tId\t\t\t\tSerialnumber\t\t\t\tPcbrand"<<endl;
	cout<<"-----\t\t--------\t\t\t-------\t\t\t\t------------\t\t\t\t\t-------"<<endl;
	while(temp!=NULL){
    cout<<temp->name;
    cout<<"\t\t"<<temp->last_name;
    cout<<"\t\t\t\t"<<temp->id;
    cout<<"\t\t\t"<<temp->serial_number;
    cout<<"\t\t\t\t"<<temp->brand;
    cout<<endl<<endl;
	temp=temp->next;	
	}
}
}






