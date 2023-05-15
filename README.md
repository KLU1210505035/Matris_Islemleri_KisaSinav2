## Kod Ne İşe Yarar Ve Nasıl Çalışır:

- generate: Bu fonksiyon bir tam sayı dizisi ve boyutunu parametre olarak alır. Diziyi stdlib.h kütüphanesinden rand fonksiyonunu kullanarak -MAX_W ile MAX_W arasında rastgele sayılarla doldurur.
- function1: Bu fonksiyon bir tam sayı dizisi ve boyutunu parametre olarak alır. Diziyi kabarcık sıralama algoritması kullanarak artan sırada sıralar. Dizinin iki elemanını geçici bir değişken kullanarak ilk eleman ikinci elemandan büyükse yer değiştirir.
- function2: Bu fonksiyon bir tam sayı dizisi ve boyutunu parametre olarak alır. Dizinin maksimum alt dizi toplamının ortalamasını döndürür. Maksimum alt dizi toplamı, dizideki bitişik elemanların en büyük toplamıdır. Fonksiyon, maksimum alt dizi toplamını saklamak için t adında bir değişken, mevcut alt dizi toplamını saklamak için current_sum adında bir değişken ve maksimum toplama sahip alt dizi sayısını saklamak için count adında bir değişken kullanır. Dizinin üzerinde yineleyerek bu değişkenleri uygun şekilde günceller.
- function3: Bu fonksiyon iki tane iki boyutlu tam sayı dizisi ve boyutlarını parametre olarak alır. İlk dizi g, G_SIZE düğümlü ağırlıklı bir grafiği temsil eder; burada g[i][j], i düğümünden j düğümüne olan kenarın ağırlığı veya kenar yoksa 0’dır. İkinci dizi d, grafikteki mesafe matrisini temsil eder; burada d[i][j], i düğümünden j düğümüne olan en kısa mesafe veya yol yoksa INF’dir. Fonksiyon, Floyd-Warshall algoritmasını kullanarak grafikten mesafe matrisini hesaplar. Mesafe matrisini kenarların ağırlıklarıyla veya köşegen elemanlar için 0 veya var olmayan kenarlar için INF ile başlatır. Ardından tüm olası ara düğümler k üzerinde yineleyerek mesafe matrisini günceller; eğer d[i][k] != INF ve d[k][j] != INF ve d[i][k] + d[k][j] < d[i][j] ise d[i][j] = d[i][k] + d[k][j] olur.

Sonuç olarak, bu program rastgele sayılarla bir dizi oluşturur, bu diziyi sıralar ve bu sıralı diziden bir ortalama değer hesaplar. Daha sonra bir grafın her düğüm çifti arasındaki en kısa yolları bulur ve bu yollar arasından belirli bir eşiği aşmayanları yazdırır. Tüm bu işlemlerin çalışma süresini de hesaplar ve sonunda yazdırır.
 
 ## Kodun Zaman Karmaşıklığını Adım Adım Gösterimi:

Zaman karmaşıklığı, bir algoritmanın çalışma süresinin girdi boyutuyla nasıl büyüdüğünün bir ölçüsüdür. Genellikle en kötü durum senaryosunda bir üst sınır veren büyük O gösterimi kullanılarak ifade edilir.
Kodun dört işlevi vardır: generate, function1, function2 ve function3. Her işlevin, giriş dizisinde veya matriste kaç kez döngü yaptığına bağlı olarak farklı bir zaman karmaşıklığı vardır.

- generate işlevi, O (n) zaman karmaşıklığına sahiptir; burada n, dizinin boyutudur. Bunun nedeni, dizinin içinden bir kez geçmesi ve her öğeye rastgele bir değer atamasıdır.

- function1 işlevi, O (n^2) zaman karmaşıklığına sahiptir; burada n, dizinin boyutudur. Bunun nedeni, diziyi sıralamak için kabarcık sıralamayı kullanmasıdır; bu, yanlış sıradalarsa bitişik öğeleri tekrar tekrar değiştirerek çalışan karşılaştırmaya dayalı bir sıralama algoritmasıdır1. Kabarcık sıralama, dizi halihazırda sıralandığında en kötü durum ve ortalama durum zaman karmaşıklığı O (n^2) ve en iyi durum zaman karmaşıklığı O (n) değerine sahiptir1.

- function2 işlevi, O (n) kadar bir zaman karmaşıklığına sahiptir; burada n, dizinin boyutudur. Bunun nedeni, dizi boyunca bir kez döngü yapması ve Kadane'nin algoritmasını2 kullanarak maksimum alt dizi toplamının ortalamasını hesaplamasıdır. Kadane'nin algoritması, tek bir geçişte mevcut toplamı ve o ana kadarki maksimum toplamı takip eden dinamik bir programlama tekniğidir2.

- function3 işlevi, O (n^3) zaman karmaşıklığına sahiptir; burada n, matrisin boyutudur. Bunun nedeni, ağırlıklı bir grafikteki tüm köşe çiftleri arasındaki en kısa yolları bulmak için Floyd-Warshall algoritmasını kullanmasıdır3. Floyd-Warshall algoritması, iç içe bir döngüde3 ara köşeleri kullanarak bir mesafe matrisini güncelleyerek çalışan tüm çiftlerden oluşan bir en kısa yol algoritmasıdır.

Bu nedenle kodun toplam zaman karmaşıklığı, en yüksek dereceli terimin hakim olduğu O (n + n^2 + n + n^3) = O (n^3) şeklindedir.

 ## Verilen Kodun Nasıl Geliştirilebileceği İçin Öneriler:
 
 1)  Yorum Ekleme: Her ne kadar kod düzgün görünse de, bazı kısımları anlamak biraz zor olabilir. Her fonksiyon için ne yaptığını açıklayan bir yorum satırı eklemek yardımcı olabilir.
 
 2)  Veri Güvenliği: rand() fonksiyonu gerçekten rastgele sayılar üretmez, bu nedenle daha güvenli bir alternatif kullanmayı düşünebilirsiniz. ( srand() vb. )

 3) Fonksiyon Adlandırma: function1, function2 ve function3 isimlerindeki fonksiyonlar, ne yaptıklarını tam olarak açıklamıyor. Bu fonksiyonların ne yaptıklarını daha iyi anlamak için daha açıklayıcı isimler (Türkçe Ve Uygun Tanımlarla) kullanabilirsiniz.
 
 4)  Daha Verimli Sıralama: function1 fonksiyonunda balon sıralaması kullanılmış. Bu sıralama algoritması genellikle yavaştır. Bu nedenle birleştirme sıralaması (merge sort) gibi algoritmalara geçmek kodun performansını artırabilir.
 
 ## YenilenmisKod.cpp deki Kod da Çalışma Zamanı Ve Zaman Karmaşıklığı:

Böylece, bu programın genel zaman karmaşıklığı, en yüksek karmaşıklığa sahip olan function3'ten dolayı O(V^3)'dir. Bu yüzden genel zaman karmaşıklığı O(V^3)'tir. Çalışma Zamanı ise 0.008000 sn dir.

 ## Her İki Kodun Zaman Karmaşıklıkları ve Çalışma Sürelerinin Karşılastırılması:
#### AA_Odev2_1(1):
- Çalışma zamanı: 0.010000 sn
- Zaman Karmaşıklığı: O(n^3)
#### YenilenmisKod:
- Çalışma zamanı: 0.008000 sn
- Zaman Karmaşıklığı: O(V^3)
