**This is a README file which explains the program in the file [source_code](https://github.com/yushananda/Game-of-Blocks/blob/main/Assignment2/source_code#L20). It aims to briefly explain what each function in the smart contract does.**

# MetaCoin
The main contract. We first define a mapping known as balances, from address data type to uint256 data type. We then define an event 'Transfer' to enable the user to transfer funds. It takes the sender's address, receiver's address and the amount to be transferred as parameters.
### constructor()
A constructor in this contract is used to set the intial balnce of the contract owner to 100K coins.
### sendCoin()
This function uses the 'Transfer' event defined in the main body of the contract to send coins from one address to another. It first checks if the balance of the sender is less than the amount that is to be sent. If it is, the function returns false. Else, the transfer event is emitted.
### getBalance()
This function takes an address type variable as its parameter and returns a uint256 type variable containing the balance corresponding to the address.

# Loan
This contract is derived from the above mentioned contract. We first define a mapping known as loans in private visibility mode, from address type variable to uint256 data type. We then define an event called 'Request' with the address of the sender, the principal amount, rate of interest, time and amount of compound interest as parameters.  private variable of type address called 'Owner' 
### isOwner()
A modifer that uses the 'require' keyword to check if the address is the same as 'msg.sender' (i.e. the owner). This will be used to allow only the owner of the contract to use specific functions later in this program.
### constructor()
A constructor in this contract is used to set the Owner variable as the address of the contract owner.
### getCompoundInterest()
A function to calculate compound interest for given principal, rate of interest and time period. Due to Solidity's poor support of fractions, a 'lazy compounding' algorithm has been used. Check [this](https://medium.com/coinmonks/math-in-solidity-part-4-compound-interest-512d9e13041b) for the details on the same.
### reqLoan()
This function uses the getCompoundInterest() function to calculate the interest and store it in a uint256 variable called toPay. Then, it stores the loan request in the loans mapping. Next, it emits this request using the 'Request' event defined earlier. Lastly, it returns true if the mapping is successful.
### getOwnerBalance()
Uses the getBalance() function to get the owner's balance.
### viewDues()
This function uses the 'isOwner' modifier to ensure that only the contract owner has access. It allows the owner to view their loans.
### settleDues()
As in the viewDues() funtion, only the owner has access. The sendCoin() function is invoked to send coins to the address of the person whom the owner owes money. Following this, the pending loans are set to zero.
