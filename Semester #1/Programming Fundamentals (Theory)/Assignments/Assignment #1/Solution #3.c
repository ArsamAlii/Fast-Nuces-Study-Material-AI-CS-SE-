 #include <stdio.h>

void input_data(void);
void calculate_shipment(int t_cookies, int cookie_in_box ,int a);
int calculate_leftover_boxes(int num_of_boxes,int t_noofboxes);
int calculate_leftover_cookies(int t_cookies, int cookie_in_box);
void output_result(int t_cookies, int cookie_in_box, int num_of_boxes, int letoveboxes,int letovercookies);

int main()
{
    input_data();
    
    
    return 0;
}

void input_data(void)
{	int t_cookies, cookie_in_box, num_of_boxes;
    printf("Enter total number of cookies: ");
    scanf("%d", &t_cookies);
    printf("Enter cookies in one box: ");
    scanf("%d", &cookie_in_box);
    printf("Enter number of boxes in one container: ");
    scanf("%d", &num_of_boxes);
    
    
     
    int letoverboxes = calculate_leftover_boxes( cookie_in_box,  num_of_boxes);
    int letovercookies =calculate_leftover_cookies(t_cookies, cookie_in_box );
	output_result(t_cookies, cookie_in_box, num_of_boxes, letoverboxes , letovercookies);
}

void calculate_shipment(int t_cookies, int cookie_in_box,int num_of_boxes)
{

    int t_noofboxes = t_cookies / cookie_in_box;
    int cs=t_noofboxes / num_of_boxes;
    printf("Number of boxes: %d\n", t_noofboxes); 
    printf("Number of containers shipped: %d\n", cs);
}

int calculate_leftover_cookies(int t_cookies, int cookie_in_box)
{
    int leftover_cookies = t_cookies % cookie_in_box;
	
    return leftover_cookies;
}
int calculate_leftover_boxes(int num_of_boxes,int t_noofboxes)
{
    int leftover_boxes = t_noofboxes % num_of_boxes;
	
    return leftover_boxes;
}



void output_result(int t_cookies, int cookie_in_box, int num_of_boxes,int letoverboxes, int letovercookies)
{

    calculate_shipment(t_cookies, cookie_in_box,num_of_boxes);
    
	
    printf("Leftover cookies: %d\n", letovercookies);
    printf("Leftover boxes: %d\n", letoverboxes);
}

