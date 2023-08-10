import React from 'react'

export default function Profile() {

    return (
        <>
            <div class="container mt-5">
                <div class="row">
                    <div class="col-md-4">
                        <div class="card">
                            <img src="profile.avif" class="card-img-top" alt="Profile Image" width={'300px'}/>
                                <div class="card-body">
                                    <h2 class="card-title">Name: John Doe</h2>
                                </div>
                        </div>
                    </div>
                    <div class="col-md-8">
                        <h2>About Me</h2>
                        <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla facilisi. Suspendisse potenti.</p>
                        <h2>Contact Information</h2>
                        <ul>
                            <li>Email: john.doe@example.com</li>
                            <li>Phone: (123) 456-7890</li>
                        </ul>
                    </div>
                </div>
            </div>
        </>
    )
}
