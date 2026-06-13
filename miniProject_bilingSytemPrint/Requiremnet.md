🧱 ✅ REQUIREMENTS
🔹 1. INPUT (User Input)

User should provide:

Number of items
For each item:
Item name
Price (per unit)
Quantity
🔸 Additional Inputs
Discount (optional → default = 0)
GST (optional → default = 18%)
🔹 2. PROCESSING (Logic)

For each item:

👉 Item total:

itemTotal = price × quantity

👉 Subtotal:

subtotal = sum of all itemTotal

👉 GST amount:

gstAmount = subtotal × GST / 100

👉 Final total:

finalTotal = subtotal + gstAmount - discount
🔹 3. OUTPUT (Formatted Bill)

You must print:

Table with:
Item name (left aligned)
Quantity (center/right)
Price (right aligned)
Total (right aligned)
Then summary:
Subtotal
GST
Discount
Final Total
🧾 ✅ EXPECTED BILL OUTPUT (Sample)
--------------------------------------------------------
| Item        | Qty | Price    | Total               |
--------------------------------------------------------
| Pen         |   2 |      10  |      20             |
| Book        |   1 |      50  |      50             |
| Bag         |   1 |     500  |     500             |
--------------------------------------------------------
| Subtotal                        |     570          |
| GST (18%)                       |     102.6        |
| Discount                        |      20          |
--------------------------------------------------------
| Final Total                     |     652.6        |
--------------------------------------------------------