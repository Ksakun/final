#include <stdio.h>
#include <string.h>


// @@@@@@@@@@@@@@@@@@@@@@@@@@@
// Predefine
#define NAME_MAX_LEN 100
#define ADDR_MAX_LEN 200
#define PHONE_MAX_LEN 20
#define EMAIL_MAX_LEN 50
#define BIO_MAX_LEN 500
#define DATE_MAX_LEN 100
#define BOOK_MAX_LEN 1000



// @@@@@@@@@@@@@@@@@@@@@@@@@@@
// Author struct

typedef struct author_s author_t;
struct author_s{
	char name[NAME_MAX_LEN];
	char address[ADDR_MAX_LEN];
	char phone_number[PHONE_MAX_LEN];
	char email[EMAIL_MAX_LEN];
	char biography[BIO_MAX_LEN];
};

// @@@@@@@@@@@@@@@@@@@@@@@@@@@
// Book struct

typedef struct book_s book_t;
struct book_s{
	int id;
	char name[NAME_MAX_LEN];
	char pub_date[DATE_MAX_LEN];
	char pub_name[NAME_MAX_LEN];
	author_t author;
};

// @@@@@@@@@@@@@@@@@@@@@@@@@@@
// Book list struct

typedef struct book_list_s book_list_t;
struct book_list_s{
	int len;
	book_t book[BOOK_MAX_LEN];
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@
// Add Function

int add(book_list_t *book_list) {
	int pos = book_list->len;

	if (strlen(book_list->book[pos].name) != 0) {
		printf("Duplicated!! Book ID Should be unique!!");
		return -1;
	}

	char name[NAME_MAX_LEN];
	char pub_date[DATE_MAX_LEN];
	char pub_name[NAME_MAX_LEN];
	char auth_phone[PHONE_MAX_LEN];
	char auth_name[NAME_MAX_LEN];
	char addr[ADDR_MAX_LEN];
	char email[EMAIL_MAX_LEN];
	char bio[BIO_MAX_LEN];

	printf("Enter Book name : ");
	fgets(name, NAME_MAX_LEN, stdin);
	printf("Enter Publication date (YY/MM/DD, only numbers): ");
	fgets(pub_date, DATE_MAX_LEN, stdin);
	printf("Enter Publisher name: ");
	fgets(pub_name, NAME_MAX_LEN, stdin);
	printf("Enter Author phone number : ");
	fgets(auth_phone, PHONE_MAX_LEN, stdin);
	printf("Enter Author name: ");
	fgets(auth_name, NAME_MAX_LEN, stdin);
	printf("Enter Author adderss: ");
	fgets(addr, ADDR_MAX_LEN, stdin);
	printf("Enter Author Email Address: ");
	fgets(email, EMAIL_MAX_LEN, stdin);
	printf("Enter Author Short Biography: ");
	fgets(bio, BIO_MAX_LEN, stdin);

	book_list->book[pos].id = pos;
	memcpy(book_list->book[pos].name, name, strlen(name));
	memcpy(book_list->book[pos].pub_date, pub_date, strlen(pub_date));
	memcpy(book_list->book[pos].pub_name, pub_name, strlen(pub_name));
	memcpy(book_list->book[pos].author.phone_number, auth_phone, strlen(auth_phone));
	memcpy(book_list->book[pos].author.name, auth_name, strlen(auth_name));
	memcpy(book_list->book[pos].author.address, addr, strlen(addr));
	memcpy(book_list->book[pos].author.email, email, strlen(email));
	memcpy(book_list->book[pos].author.biography, bio, strlen(bio));

	book_list->len += 1;

	printf("Add Finished.\n\n");
	return 0;
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@
// Update Function

int update(book_list_t *book_list, int n) {
	if (n <= 0) {
		printf("ID is less equal 0");
		return -1;
	}

	if (strlen(book_list->book[n].name) == 0) {
		printf("None exist!! Book ID Should be added first!!");
		return -2;
	}

	int i = 0;
	int pos = n - 1;

	char name[NAME_MAX_LEN];
	char pub_date[DATE_MAX_LEN];
	char pub_name[NAME_MAX_LEN];
	char auth_phone[PHONE_MAX_LEN];
	char auth_name[NAME_MAX_LEN];
	char addr[ADDR_MAX_LEN];
	char email[EMAIL_MAX_LEN];
	char bio[BIO_MAX_LEN];

	printf("Enter Book name : ");
	fgets(name, NAME_MAX_LEN, stdin);
	printf("Enter Publication date (YY/MM/DD, only numbers): ");
	fgets(pub_date, DATE_MAX_LEN, stdin);
	printf("Enter Publisher name: ");
	fgets(pub_name, NAME_MAX_LEN, stdin);
	printf("Enter Author phone number : ");
	fgets(auth_phone, PHONE_MAX_LEN, stdin);
	printf("Enter Author name: ");
	fgets(auth_name, NAME_MAX_LEN, stdin);
	printf("Enter Author adderss: ");
	fgets(addr, ADDR_MAX_LEN, stdin);
	printf("Enter Author Email Address: ");
	fgets(email, EMAIL_MAX_LEN, stdin);
	printf("Enter Author Short Biography: ");
	fgets(bio, BIO_MAX_LEN, stdin);

	memcpy(book_list->book[pos].name, name, strlen(name));
	memcpy(book_list->book[pos].pub_date, pub_date, strlen(pub_date));
	memcpy(book_list->book[pos].pub_name, pub_name, strlen(pub_name));
	memcpy(book_list->book[pos].author.phone_number, auth_phone, strlen(auth_phone));
	memcpy(book_list->book[pos].author.name, auth_name, strlen(auth_name));
	memcpy(book_list->book[pos].author.address, addr, strlen(addr));
	memcpy(book_list->book[pos].author.email, email, strlen(email));
	memcpy(book_list->book[pos].author.biography, bio, strlen(bio));

	printf("Update Finished!!\n\n");
	return 1;
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@
// Delete Function

int delete(book_list_t *book_list, int x) {
	if (book_list->len <= 0) {
		printf("Book list has no book!\n");
		return -2;
	}

	int pos = -1;
	int i = 0;
	for ( ; i < book_list->len; i++) {
		if (book_list->book[i].id == x) {
			book_list->book[i].id = 0;
			memset(book_list->book[i].name, 0, NAME_MAX_LEN);
			memset(book_list->book[i].pub_date, 0, DATE_MAX_LEN);
			memset(book_list->book[i].pub_name, 0, NAME_MAX_LEN);
			memset(book_list->book[i].author.name, 0, NAME_MAX_LEN);
			memset(book_list->book[i].author.address, 0, ADDR_MAX_LEN);
			memset(book_list->book[i].author.phone_number, 0, PHONE_MAX_LEN);
			memset(book_list->book[i].author.email, 0, EMAIL_MAX_LEN);
			memset(book_list->book[i].author.biography, 0, BIO_MAX_LEN);
			pos = i;
			break;
		}
	}
	if(pos == -1) {
		printf("Delete Failed.\n\n");
		return -1;
	}

	for (i = pos ; i < book_list->len - 1; i++) {
		book_list->book[i].id = book_list->book[i+1].id;
		memcpy(book_list->book[i].name, book_list->book[i+1].name, strlen(book_list->book[i+1].name));
		memcpy(book_list->book[i].pub_date, book_list->book[i+1].pub_date, strlen(book_list->book[i+1].pub_date));
		memcpy(book_list->book[i].pub_name, book_list->book[i+1].pub_name, strlen(book_list->book[i+1].pub_name));
		memcpy(book_list->book[i].author.name, book_list->book[i+1].author.name, strlen(book_list->book[i+1].author.name));
		memcpy(book_list->book[i].author.address, book_list->book[i+1].author.address, strlen(book_list->book[i+1].author.address));
		memcpy(book_list->book[i].author.phone_number, book_list->book[i+1].author.phone_number, strlen(book_list->book[i+1].author.phone_number));
		memcpy(book_list->book[i].author.email, book_list->book[i+1].author.email, strlen(book_list->book[i+1].author.email));
		memcpy(book_list->book[i].author.biography, book_list->book[i+1].author.biography, strlen(book_list->book[i+1].author.biography));
	}

	book_list->len -= 1;

	printf("Delete Finished.\n\n");
	return 1;
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@
// Search Function

int search(book_list_t *book_list, int id) {
	int flag = 0;
	int i = 0;
	for ( ; i < book_list->len; i++) {
		if (book_list->book[i].id == id) {
			printf("Book searched! Your Book info will show under. \n");
			printf("------------------------------------------------------------------\n");
			printf("Book id: %d\n", book_list->book[i].id);
			printf("Book name: %s\n", book_list->book[i].name);
			printf("Publication date: %d\n", book_list->book[i].pub_date);
			printf("Publisher name: %s \n", book_list->book[i].pub_name);
			printf("Author name: %s\n", book_list->book[i].author.name);
			printf("Author address: %s\n", book_list->book[i].author.address);
			printf("Author phone number: %s\n", book_list->book[i].author.phone_number);
			printf("Author Email address: %s\n", book_list->book[i].author.email);
			printf("Author Short Biography: %s\n", book_list->book[i].author.biography);
			return 1;
		}
	}
	printf("There is no such Book.\n");
	return -1;
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@
// Display Function

int display(book_list_t *book_list) {
	int i = 0;
	for ( ; i < book_list->len; i++) {
		printf("\n**** Book info****\n");
		printf("Book id : %d\n", book_list->book[i].id);
		printf("Book name: %s\n", book_list->book[i].name);
		printf("Publisher's name: %s\n", book_list->book[i].pub_name);
		printf("Publishing date: %s\n", book_list->book[i].pub_date);
		printf("Author's name: %s\n", book_list->book[i].author.name);
		printf("Author's phone number: %s\n", book_list->book[i].author.phone_number);
		printf("Author's address: %s\n", book_list->book[i].author.address);
		printf("Author's email: %s\n", book_list->book[i].author.email);
		printf("Author's biography: %s\n", book_list->book[i].author.biography);
	}
	return 0;
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@
// Save file Function

int save_file(book_list_t *book_list) {
	int i = 0;
	FILE *fp;
	if ((fp = fopen("book_list.txt", "w")) == NULL) {
		printf("Fail to open a file");
		return -2;
	}

	fprintf(fp, "**** Book info****\n\n");
	fprintf(fp, "----------------------------------------\n");

	for ( ; i < book_list->len; i++) {
		fprintf(fp, "@ Book id : %d\n", book_list->book[i].id);
		fprintf(fp, "@ Book name: %s\n", book_list->book[i].name);
		fprintf(fp, "@ Publisher's name: %s\n", book_list->book[i].pub_name);
		fprintf(fp, "@ Publishing date: %s\n", book_list->book[i].pub_date);
		fprintf(fp, "@ Author's name: %s\n", book_list->book[i].author.name);
		fprintf(fp, "@ Author's phone number: %s\n", book_list->book[i].author.phone_number);
		fprintf(fp, "@ Author's address: %s\n", book_list->book[i].author.address);
		fprintf(fp, "@ Author's email: %s\n", book_list->book[i].author.email);
		fprintf(fp, "@ Author's biography: %s\n", book_list->book[i].author.biography);
		fprintf(fp, "----------------------------------------\n");
	}

	fclose(fp);
	return 0;
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@
// Main

int main() {
	int c;

	book_list_t book_list;

	while (1) {
		c = 0;
		printf("\n---------------------------------------------------------------------\n");
		printf("1. Add book information\n");
		printf("2. Update book information\n");
		printf("3. Delete book information\n");
		printf("4. Search book information\n");
		printf("5. Display a list of all book\n");
		printf("6. Exit program\n");
		printf("Select your operation!   ");
		scanf("%d", &c);
		printf("\n---------------------------------------------------------------------\n");

		switch (c) {
			case 1: { //add
					add(&book_list);
					break;
				}
			case 2: { //update
					int n;
					printf("Which book to update? Endter book id: ");
					scanf("%d", &n);
					update(&book_list, n);
					break;
				}
			case 3: {//delete
					int k;
					printf("Which book to delete? Enter book id: ");
					scanf("%d", &k);
					delete(&book_list, k);
					break;
				}
			case 4: { //search
					int n;
					printf("Which book to search? Enter book id: ");
					scanf("%d", &n);
					search(&book_list, n);
					break;
				}
			case 5: { //display 
					display(&book_list);
					save_file(&book_list);
					break;
				}
			case 6: {
					printf("Success to finish the program!");
					return 1;
				}
			default:
				printf("Error. Run program again!");
				return 0;
		}
	}
}
