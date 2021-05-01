pragma solidity >=0.4.0 <0.6.0;

//Contract of credit card
contract Card {

    //Address of user, who interacts with contract
    address user;

    //Mappings between user and funds
    mapping(address => uint) funds;
    
    //Contract constructor
    constructor() public {
        user = msg.sender;
    }

    //Method to deposit funds on the card
    function deposit() public payable {
        funds[msg.sender] += msg.value;
    }

    //Method to withdraw funds from the card
    function withdraw(uint amount) public {
        if (funds[msg.sender] >= amount) {
            funds[msg.sender] -= amount;
            msg.sender.transfer(amount);
        }
    }

    //Method to check funds amount on the card
    function checkFunds() public view returns(uint) {
        return funds[msg.sender];
    }

    //Method to kill smart contract, if the method is called by a user, who is not the owner of the card
    function kill() public {
        if (msg.sender == user)
            selfdestruct(user);
    }
}