import React, { useEffect, useRef, useState } from 'react'
import { useNavigate } from "react-router-dom";
import Axios from 'axios';


export default function Component() {
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
    const [name, setName] = useState('');
    let loadFirstTime = false;
    const navigate = useNavigate();

    const registration = async (event) => {
        event.preventDefault();
    
        const user = { name, email, password }; // Object shorthand syntax
        
        try {
            const response = await Axios.post("http://localhost:3001/register", user);
            // alert(response.data)
            console.log(response.data); // Assuming you want to log the response data
        } catch (error) {
            console.error("Error:", error);
        }
    };
    

    const login = async (event) => {
        event.preventDefault();
        let formData = { email: email, password: password};
        
        try {
            const response = await Axios.post("http://localhost:3001/login", formData);
            
            if(response.status === 200) {
                navigate("/profile");
            }
        } catch (error) {
            console.error("Error:", error);
        }
    }


    // Model Observation
    const checkUpdate = async () => {
        try {
            const response = await fetch('http://localhost:3001/watchJsonFile');
            // console.log(response.text());
            alert("Database is updated")
            checkUpdate();
        } catch (error) {
            console.error('Error fetching JSON data:');
        }
    };

    useEffect(() => {
        if (!loadFirstTime) {
            checkUpdate();
            loadFirstTime = true;
        }
    }, []);


    // useEffect(() => {
    //     console.log(model.totalUser);

    //     if (totalUser === model.totalUser) {
    //         return;
    //     }

    //     // This effect will run whenever 'data' changes
    //     console.log('Data changed:');
    //     // Perform your response actions here
    // }, [totalUser]);

    return (
        <>
            <h1>Registration</h1>
            <form onSubmit={registration}>
                <div className='row'>
                    <label className='col-sm-2'>Name:</label>
                    <input className='col-sm-6' type="text" onChange={(e) => setName(e.target.value)} />
                </div>
                <br />

                <div className='row'>
                    <label className='col-sm-2'>Email:</label>
                    <input className='col-sm-6' type="text" onChange={(e) => setEmail(e.target.value)} />
                </div>
                <br />

                <div className='row'>
                    <label className='col-sm-2'>Password:</label>
                    <input type="password" className='col-sm-6' onChange={(e) => setPassword(e.target.value)} />
                </div>
                <br />

                <div className='row'>
                    <input className='col-sm-4' type="submit" />
                </div>
            </form>


            <br /><br />
            <h1>Login</h1>
            <form onSubmit={login}>
                <div className='row'>
                    <label className='col-sm-2'>Email:</label>
                    <input className='col-sm-6' type="text" onChange={(e) => setEmail(e.target.value)} />
                </div>
                <br />

                <div className='row'>
                    <label className='col-sm-2'>Password:</label>
                    <input type="password" className='col-sm-6' onChange={(e) => setPassword(e.target.value)} />
                </div>
                <br />

                <div className='row'>
                    <input className='col-sm-4' type="submit" />
                </div>
            </form>
        </>
    )
}
