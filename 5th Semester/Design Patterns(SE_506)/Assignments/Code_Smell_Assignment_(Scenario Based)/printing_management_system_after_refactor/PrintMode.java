package printing_management_system_after_refactor;


public abstract class PrintMode {
    private int number_of_pages, page_size, cost_per_page;
    private String orientation;
    private double color_intensity;


    public int getNumber_of_pages() {
        return number_of_pages;
    }

    public int getPage_size() {
        return page_size;
    }

    public int getCost_per_page() {
        return cost_per_page;
    }

    public String getOrientation() {
        return orientation;
    }

    public double getColor_intensity() {
        return color_intensity;
    }

    public void setNumber_of_pages(int number_of_pages) {
        this.number_of_pages = number_of_pages;
    }

    public void setPage_size(int page_size) {
        this.page_size = page_size;
    }

    public void setCost_per_page(int cost_per_page) {
        this.cost_per_page = cost_per_page;
    }

    public void setOrientation(String orientation) {
        this.orientation = orientation;
    }

    public void setColor_intensity(double color_intensity) {
        this.color_intensity = color_intensity;
    }
}
