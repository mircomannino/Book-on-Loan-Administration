# Loan Administration

This application can help you to manage you borrowing book.

Once you have compiled the "loan_administration.cc" file and once you execute it,
will appear a menu. In this menu you can:
* List of all books on loan
* Search for a book on loan
* Add a book on loan
* Delete a book on loan

## Header file
* date.h: contains the class "Date", used to manage the loans
* loan.h: contains the class "Loan", it represents a single loan object
* loan_administrator.h: constains the class "LoanAdministrator" that manage all the loan in the application.
## Example
This is the menu:
```
1- Print all loans
2- Search for loan title
3- Add a loan
4- Delete a loan
5- Exit
Your choice:
```
For every option there a sample of what the input and the output are.
```
1- Print all loans

	TITLE		PERSON		START			END
	Math		Jimmy		2019/08/20		--/--/--
	Story		Anna		2019/05/30		--/--/--
```


```
2- Search for loan title

	Insert a title: Math
	TITLE		PERSON		START			END
	Math		Jimmy		2019/08/20		--/--/--

	OR

	Insert a title: title_not_in_list
	Title not found
```
```
3- Add a loan

	Insert title: Story
	Insert person: Anna
	Insert start date: 2019/05/30
	Insert end date: --/--/--
	Loan added successfully

Note: if you want to add a "non-specific" date, you have to insert "--/--/--".
```

```
4- Delete a loan

	Insert a title to delete: Story
	Title deleted successfully

	OR

	Insert a title: title_not_in_list
	The title you insert does not exist
```
