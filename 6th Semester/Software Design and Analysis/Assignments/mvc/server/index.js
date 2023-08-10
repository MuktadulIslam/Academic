const express = require("express");
const cors = require("cors");
const fs = require('fs');
const jsonFilePath = './user.json';


const app = express();
app.use(express.json());
app.use(cors());
let previousUserData = JSON.stringify(JSON.parse(fs.readFileSync(jsonFilePath)));
const dataCheckingTime = 2000;



app.get('/watchJsonFile', (req, res) => {
    console.log("request come from frontend to observe");
    const interval = setInterval(() => {
        const userData = JSON.stringify(JSON.parse(fs.readFileSync(jsonFilePath)));
        // console.log("hi")

        if (previousUserData != userData) {
            console.log("Change detected");
            previousUserData = userData; // Update the previousUserData
            clearInterval(interval);
            res.send("database is updated");
        }
        // console.log("hello world");
    }, dataCheckingTime);

    // // Stop the interval when the request is closed
    // res.on('close', () => {
    //     clearInterval(interval);
    //     console.log("Interval stopped");
    // });
});


app.post('/register', async (req, res) => {
    const user = req.body;

    try {
        const data = await fs.promises.readFile(jsonFilePath, 'utf8');
        const existingData = JSON.parse(data);

        existingData.push(user);

        await fs.promises.writeFile(jsonFilePath, JSON.stringify(existingData, null, 2), 'utf8');
        
        console.log('Data added and JSON file updated successfully.');
        res.status(200).send('Data added and JSON file updated successfully.');
    } catch (error) {
        console.error('Error:', error);
        res.status(500).send('An error occurred while processing the request.');
    }
});

app.post('/login', async (req, res) => {
    const user = req.body;
    console.log(user);

    try {
        const userData = JSON.parse(await fs.promises.readFile(jsonFilePath, 'utf8'));

        const foundUser = userData.find(existingUser => 
            existingUser.email === user.email && existingUser.password === user.password
        );

        if (foundUser) {
            res.status(200).send('Login successful');
        } else {
            res.status(401).send('Login failed');
        }
    } catch (error) {
        console.error('Error:', error);
        res.status(500).send('An error occurred while processing the request.');
    }
});



app.listen(3001, () => {
    console.log("Running backend server on port 3001");
});