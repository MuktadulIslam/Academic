import fs from 'fs'; // Node.js file system module
import userData from './user.json';

let totalUser = userData.length;

const addUser = (user) => {
    console.log(user);
    userData.push(user); // Add the new user object to the userData array
    totalUser++;

    // Write the updated data back to the user.json file
    fs.writeFileSync('./user.json', JSON.stringify(userData, null, 2));

    console.log('User added successfully.');
}

export default { totalUser, addUser };
