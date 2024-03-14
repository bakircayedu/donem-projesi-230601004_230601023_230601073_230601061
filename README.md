[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/E4yKpUg3)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=14014907&assignment_repo_type=AssignmentRepo)




RSA (Rivest-Shamir-Adleman), bir kriptografik algoritmadır ve genellikle güvenli iletişim sağlamak için kullanılır. Adını, yaratıcıları Ron Rivest, Adi Shamir ve Leonard Adleman'dan alır. RSA, açık anahtarlı kriptografinin en bilinen ve yaygın olarak kullanılan yöntemlerinden biridir.

RSA'nın temelinde şu anahtar kavramları bulunur:

Açık Anahtar (Public Key): Herkes tarafından bilinen ve herkesin kullanabileceği bir anahtardır. Genellikle iletişimde mesajların şifrelenmesinde kullanılır.

Özel Anahtar (Private Key): Sadece anahtar sahibi tarafından bilinen gizli bir anahtardır. Şifrelenmiş mesajların çözülmesinde kullanılır.

RSA algoritmasının çalışma prensibi şu adımlara dayanır:

Anahtar Üretimi: İlk olarak, iki büyük asal sayı seçilir. Bu sayılar, çoğunlukla yüzlerce hane uzunluğunda olur. Bu asal sayılar p ve q olarak adlandırılır. Bu sayılar genellikle çok büyük olduğu için rastgele seçilirler ve çok büyük olasılıkla çarpanları hakkında bilgi sahibi olmak zordur. Sonrasında, bu asal sayılarla işlem yaparak bir n ve özel bir e belirlenir.

Anahtar Çiftlerinin Oluşturulması: n ve e, açık anahtarı oluşturur. Özel anahtar ise p, q ve e ile birlikte belirlenir. Açık anahtar (n, e) herkese açık bir şekilde yayınlanırken, özel anahtar (p, q, e) gizli tutulur.

Şifreleme: Bir mesajı (sayısal bir değere dönüştürülmüş) şifrelemek için alıcı tarafından yayınlanan açık anahtar kullanılır. Mesaj, modüler aritmetik işlemleri ile şifrelenir. Şifreli metin, orijinal mesajı çözmek için sadece özel anahtarla çözülebilecek bir formda oluşturulur.

Çözme: Şifreli mesajı almak için alıcı, özel anahtarı kullanır. Özel anahtar kullanılarak, şifreli mesaj orijinal mesajı elde etmek için çözülür.

RSA'nın güvenliği, iki büyük asal sayıyı çarpanlarına ayırmanın zorluğuna dayanır. Bu işlem, büyük bir sayının asal çarpanlarını bulmanın zorluğu nedeniyle klasik bilgisayarlar için oldukça zaman alabilir. Bu nedenle, doğru bir şekilde uygulandığında, RSA şifreleme güvenlidir. Ancak, bilgisayar gücü arttıkça ve kriptografik algoritmaları kırmak için yeni teknikler geliştikçe, RSA'nın güvenliği zamanla değişebilir. Bu nedenle, zaman zaman güçlü anahtarlar kullanmak ve güvenlik önlemlerini güncellemek önemlidir.
