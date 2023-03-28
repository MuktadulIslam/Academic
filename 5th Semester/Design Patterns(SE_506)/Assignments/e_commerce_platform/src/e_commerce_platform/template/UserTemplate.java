package e_commerce_platform.template;

public abstract class UserTemplate {
    private String userName;
    private String password;
    private String email;
    private String address;

    public UserTemplate(String userName, String password, String email, String address) {
        this.userName = userName;
        this.password = password;
        this.email = email;
        this.address = address;
    }

    public final void changePassword(){
        String oldPassword, newPassword, confirmPassword;
        oldPassword = getOldPassword();

        for(;;) {
            if (oldPassword == this.password) {
                for(;;) {
                    newPassword = getNewPassword();
                    confirmPassword = getConfirmPassword();
                    if(newPassword == confirmPassword){
                        this.password = newPassword;
                        System.out.println("Password successfully changed!!!");
                        break;
                    }
                    else{
                        System.out.println("New password and Confirm password does not match!!!!. Please try again.");
                    }
                }
                break;
            } else {
                System.out.println("Old password does not match!!!!. Please try again.");
            }
        }
    }

    public abstract String getOldPassword();
    public abstract String getNewPassword();
    public abstract String getConfirmPassword();
}
