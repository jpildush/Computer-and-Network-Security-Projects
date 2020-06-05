    
    /*
    *   generatePass - This method captures the user selected length and uses it to generate a random password while abiding by these criterias:
    *                                   1. Password must be between 8 and 16 characters in length
    *                                   2. A strong password will contain at least 1 number
    *                                   3. A strong password will contain at least 1 uppercase and 1 lowercase letter
    *                                   4. A strong password will contain more than 2 special characters
    *                                   5. The best password would not have too many duplicate characters
    *
    */
    function generatePass()
    {
        var passLen = $("input[name=passLength]").val();
        var password = "";
        if(!isNaN(passLen))
        {
            if(passLen >= 8 && passLen <= 16)
            {
                for (i = 0;i < passLen;i++)
                {
                    password += genRan(i);
                }
                document.getElementById('newPass').value = password;
            }
            else
                alert("Rule Violation: Length of password must be between 8 and 16!");
        }
        else
            alert("Please Enter a Number!");

    }

    /*
    *   genRan - This method generates the password using the passed through length. 
                 Every even number position of the password will be a special character
                 Every odd number position of the password will be a lower or upper case letter
            @param lenID - The desired length of the password that will be generated
    *
    */
    function genRan(lenID)
    {
        var randChar = '';
        var charList = "12345!@#$%^&*()_+?67890";
        var alphList = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

        if(lenID % 2 == 0)
          randChar = charList[Math.floor(Math.random()*charList.length)];
        else
          randChar = alphList[Math.floor(Math.random()*alphList.length)];

        return randChar;
    }