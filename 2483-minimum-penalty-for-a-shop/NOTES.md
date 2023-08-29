Bạn được cho nhật ký khách hàng của cửa hàng, biểu thị bằng chuỗi customers được đánh chỉ mục là 0, chỉ bao gồm ký tự 'N' hoặc 'Y'
​
Nếu ký tự thứ i là 'Y', Điều đó nghĩa là khác hàng đến vào giờ thứ i.
Trong khi 'N' chỉ ra là không có khách hàng nào đến vào giờ thứ i.
​
Nếu cửa hàng đóng cửa tại giờ j, nếu bị phạm ỗi thì mức phạt được tính như sau:
​
Cứ mỗi giờ khi mà cửa hàng mở cửa và không khách hàng nào đến, thì lỗi tăng lên
Cứ mỗi giờ khi cửa hàng mà đóng cửa và khách hàng đến thì lỗi tăng lên 1
​
Trả lại giờ sớm nhất mà cửa hàng phải đóng cửa để chịu mức phạt tối thiểu.